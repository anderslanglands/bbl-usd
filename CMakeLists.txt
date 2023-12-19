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
    bind/sdr.cpp
    bind/std.cpp
    bind/tf.cpp 

    bind/sdf/abstractData.cpp
    bind/sdf/allowed.cpp
    bind/sdf/assetPath.cpp
    bind/sdf/attributeSpec.cpp
    bind/sdf/changeBlock.cpp
    bind/sdf/changeList.cpp
    bind/sdf/copyUtils.cpp
    bind/sdf/data.cpp
    bind/sdf/fileFormat.cpp
    bind/sdf/layer.cpp
    bind/sdf/layerOffset.cpp
    bind/sdf/layerStateDelegate.cpp
    bind/sdf/layerTree.cpp
    bind/sdf/listOp.cpp
    bind/sdf/namespaceEdit.cpp
    bind/sdf/notice.cpp
    bind/sdf/path.cpp
    bind/sdf/pathExpression.cpp
    bind/sdf/payload.cpp
    bind/sdf/predicateExpression.cpp
    bind/sdf/primSpec.cpp
    bind/sdf/propertySpec.cpp
    bind/sdf/proxyTypes.cpp
    bind/sdf/reference.cpp
    bind/sdf/relationshipSpec.cpp
    bind/sdf/schema.cpp
    bind/sdf/spec.cpp
    bind/sdf/timeCode.cpp
    bind/sdf/types.cpp
    bind/sdf/valueTypeName.cpp
    bind/sdf/variableExpression.cpp
    bind/sdf/variantSetSpec.cpp
    bind/sdf/variantSpec.cpp

    bind/usd/attributeQuery.cpp 
    bind/usd/clipsAPI.cpp 
    bind/usd/collectionAPI.cpp 
    bind/usd/collectionMembershipQuery.cpp 
    bind/usd/common.cpp 
    bind/usd/crateInfo.cpp 
    bind/usd/editTarget.cpp 
    bind/usd/inherits.cpp 
    bind/usd/modelAPI.cpp 
    bind/usd/notice.cpp 
    bind/usd/object.cpp 
    bind/usd/payloads.cpp 
    bind/usd/primCompositionQuery.cpp 
    bind/usd/primDefinition.cpp 
    bind/usd/primRange.cpp 
    bind/usd/references.cpp 
    bind/usd/resolveInfo.cpp 
    bind/usd/resolveTarget.cpp 
    bind/usd/schemaBase.cpp 
    bind/usd/schemaRegistry.cpp 
    bind/usd/specializes.cpp 
    bind/usd/stage.cpp 
    bind/usd/stageCache.cpp 
    bind/usd/stageLoadRules.cpp 
    bind/usd/stagePopulationMask.cpp 
    bind/usd/timeCode.cpp 
    bind/usd/variantSets.cpp 

    bind/usd/geom.cpp 
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

target_link_libraries(openusd-c PUBLIC usd usdGeom sdf sdr ndr pcp)


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
