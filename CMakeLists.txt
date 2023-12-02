cmake_minimum_required(VERSION 3.15)
project(bbl-usd VERSION 0.1 LANGUAGES C CXX)

find_package(babble 0.5 CONFIG REQUIRED)
find_package(pxr REQUIRED)

# The bindfile contains all our binding definitions
set(bindfiles 
    bind/ar.cpp 
    bind/gf.cpp 
    bind/js.cpp 
    bind/pcp.cpp 
    bind/sdf.cpp 
    bind/std.cpp
    bind/tf.cpp 
    bind/usd/geom.cpp 
    bind/usd/prim.cpp 
    bind/usd/schema.cpp 
    bind/usd/usd.cpp 
    bind/vt.cpp 
)

bbl_translate_binding(
    openusd
    BINDFILES 
        ${bindfiles}
    COMPILE_ARGS 
        -Wno-deprecated-builtins 
        -DNOMINMAX 
        -D_MT 
        -DBOOST_ALL_NO_LIB 
        -D__TBB_show_deprecation_message_task_H 
)

target_link_libraries(openusd-c PUBLIC usd sdf js usdGeom)
target_compile_definitions(openusd-c PRIVATE NOMINMAX BOOST_ALL_NO_LIB __TBB_show_deprecation_message_task_H)

if (MSVC)
    target_compile_options(openusd-c PRIVATE /bigobj)
endif()

# Compile a simple test program to exercise the generated library
add_executable(usd-c-test01 usd-c-test01.c)
target_link_libraries(usd-c-test01 PUBLIC openusd-c)
target_include_directories(usd-c-test01 PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET usd-c-test01 PROPERTY C_STANDARD 99)

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
