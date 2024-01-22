cmake_minimum_required(VERSION 3.15)
project(bbl-gen-usd VERSION 0.1 LANGUAGES C CXX)

find_package(babble 0.5 CONFIG REQUIRED)
find_package(pxr REQUIRED)

include(GNUInstallDirs)

bbl_generate_binding(
    openusd
    gen.cpp
    pxrInternal_v0_23__pxrReserved__

    COMPILE_ARGS
        -DNOMINMAX
        -DBOOST_ALL_NO_LIB
        -D__TBB_show_deprecation_message_task_H
        -D_MT
        -Wno-deprecated-builtins
)

target_link_libraries(openusd-gen PUBLIC usd sdf js usdGeom)
target_compile_definitions(openusd-gen PRIVATE -DNOMINMAX -DBOOST_ALL_NO_LIB -D__TBB_show_deprecation_message_task_H)
