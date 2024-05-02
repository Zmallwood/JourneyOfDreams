#  Copyright (C) 2024 Andreas Åkerberg

project(Server)
cmake_minimum_required(VERSION 3.22)

add_definitions()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin_server)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

if(TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} " )
endif()

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(Server ${SRC_FILES})
target_include_directories(Server PUBLIC external /usr/include/postgresql)

add_library(jsoncpp STATIC ${PROJECT_SOURCE_DIR}/external/jsoncpp.cpp)

target_link_libraries(Server jsoncpp soci_core soci_postgresql)
set(PCH_FILES
    "stdafx/StdAfx.h"
)
target_precompile_headers(Server PRIVATE ${PCH_FILES})