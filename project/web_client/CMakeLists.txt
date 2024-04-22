project(Game2Emscripten)
cmake_minimum_required(VERSION 3.22)
set(MEDIA_DIR ${PROJECT_SOURCE_DIR}/Media/)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2")
#set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s EXPORTED_FUNCTIONS=\"[ '_passAssetAsArrayBuffer', '_clearScene', '_main']\" -s USE_SDL=2 -s MAX_WEBGL_VERSION=2")
set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s EXPORTED_FUNCTIONS=\"[  '_main']\" -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 --use-preload-plugins -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2 --shell-file ${CMAKE_SOURCE_DIR}/html/shell_minimal.html")
#set(CMAKE_EXE_LINKER_FLAGS "-s EXPORTED_FUNCTIONS=\"[  '_main']\" -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s NODERAWFS=1")


add_definitions()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin_web_client)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})

link_directories(~/temp/emsdk/upstream/emscripten/cache/sysroot/lib)

if(TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}" )
endif()

set (OGRE_LIBRARIES /home/andreas/SourceBuild/ogre/OgreMain)

include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_EXTERNAL ${PROJECT_SOURCE_DIR}/external/*.cpp)
add_executable(WebClient ${SRC_FILES} ${SRC_FILES_EXTERNAL})
#target_link_libraries(WebClient websocket bz2 freetype SDL2_ttf)
target_link_libraries(WebClient websocket)
set(PCH_FILES
    "stdafx/StdAfx.h"
)
target_precompile_headers(WebClient PRIVATE ${PCH_FILES})
#target_link_libraries(EmscriptenSample OgreRTShaderSystem OgreBites ${OGRE_LIBRARIES})


target_compile_features(WebClient PRIVATE cxx_std_20)
