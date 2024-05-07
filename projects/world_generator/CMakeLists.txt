#  Copyright (C) 2024 Andreas Åkerberg

project(Game2Emscripten)
cmake_minimum_required(VERSION 3.22)

#set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s EXPORTED_FUNCTIONS=\"[  '_main']\" -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 --use-preload-plugins -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]'")

add_definitions()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin_world_generator)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})

if(TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} " )
endif()

set (OGRE_LIBRARIES /home/andreas/SourceBuild/ogre/OgreMain)

include_directories(${PROJECT_SOURCE_DIR}/Samples/Character/include)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_WORLD_STRUCTURE ${PROJECT_SOURCE_DIR}/../shared/world_structure/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_COMMON ${PROJECT_SOURCE_DIR}/../shared/common/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_CONFIGURATION ${PROJECT_SOURCE_DIR}/../shared/configuration/src/*.cpp)
add_executable(WorldGenerator ${SRC_FILES} ${SRC_FILES_WORLD_STRUCTURE} ${SRC_FILES_COMMON} ${SRC_FILES_CONFIGURATION})
target_include_directories(WorldGenerator PUBLIC src)
target_include_directories(WorldGenerator PUBLIC ../shared)

set(PCH_FILES
    "stdafx/StdAfx.h"
)
target_precompile_headers(WorldGenerator PRIVATE ${PCH_FILES})

# Compile jsoncpp from source
#add_library(jsoncpp STATIC ${PROJECT_SOURCE_DIR}/external/jsoncpp.cpp)

target_link_libraries(WorldGenerator SDL2)
