cmake_minimum_required(VERSION 3.15)
project(bbl-usd VERSION 0.1 LANGUAGES C CXX)

find_package(babble 0.6 CONFIG REQUIRED)
find_package(pxr REQUIRED)

option(BUILD_EXAMPLE "Build the example program" OFF)

# The bindfile contains all our binding definitions
set(bindfiles 
    bind/ar.cpp 
    bind/gf.cpp 
    bind/js.cpp 
    bind/ndr.cpp 
    bind/pcp.cpp 
    bind/sdf.cpp
    bind/sdr.cpp
    bind/std.cpp
    bind/tf.cpp 
    bind/usd.cpp
    bind/usdGeom.cpp
    bind/usdLux.cpp
    bind/usdRender.cpp
    bind/usdShade.cpp
    bind/usdImaging.cpp
    bind/vt.cpp
)

# Configures bbl-translate to generate the shim library source and build it as
# libopenusd-c
bbl_translate_binding(
    openusd
    BINDFILES 
        ${bindfiles}
    COMPILE_ARGS 
        -Wno-deprecated-builtins 
        "-Wno-#pragma-messages"
        -DNOMINMAX 
        -D_MT 
        -DBOOST_ALL_NO_LIB 
        -D__TBB_show_deprecation_message_task_H 
)

target_link_libraries(
  openusd-c 
    PUBLIC 
      ${PXR_LIBRARIES}
)


target_compile_definitions(openusd-c PRIVATE NOMINMAX BOOST_ALL_NO_LIB __TBB_show_deprecation_message_task_H)

if (MSVC)
    target_compile_options(openusd-c PRIVATE /bigobj)
endif()

# Compile a simple test program to exercise the generated library
if (${BUILD_EXAMPLE})
add_executable(usd-c-test01 usd-c-test01.c)
target_link_libraries(usd-c-test01 PUBLIC openusd-c)
target_include_directories(usd-c-test01 PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET usd-c-test01 PROPERTY C_STANDARD 99)
endif()

# This is just here to trigger generation of compile commands for the bind file so we get LSP functionality in the bind file
add_library(bind-dummy ${bindfiles})
target_link_libraries(bind-dummy babble::bind)
target_include_directories(bind-dummy PRIVATE $<TARGET_PROPERTY:openusd-c,INCLUDE_DIRECTORIES>)
target_compile_options(bind-dummy PRIVATE $<TARGET_PROPERTY:openusd-c,COMPILE_OPTIONS>)
target_compile_definitions(bind-dummy PRIVATE $<TARGET_PROPERTY:openusd-c,COMPILE_DEFINITIONS>)

install(
  TARGETS 
    openusd-c
  LIBRARY 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME 
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
