project(Game2Emscripten)
cmake_minimum_required(VERSION 3.22)
set(MEDIA_DIR ${PROJECT_SOURCE_DIR}/Media/)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=undefined -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2 -s NO_DISABLE_EXCEPTION_CATCHING")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fsanitize=undefined -s")
set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s EXPORTED_FUNCTIONS=_main -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2 --shell-file ${CMAKE_SOURCE_DIR}/html/shell_minimal.html")

add_definitions()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin_web_client)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

if(TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}" )
endif()

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/../shared)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_EXTERNAL ${PROJECT_SOURCE_DIR}/external/*.cpp)
file(GLOB_RECURSE SRC_FILES_SHARED ${PROJECT_SOURCE_DIR}/../shared/*.cpp)
add_executable(WebClient ${SRC_FILES} ${SRC_FILES_EXTERNAL} ${SRC_FILES_SHARED})

target_link_libraries(WebClient websocket)
set(PCH_FILES
    "stdafx/StdAfx.h"
)
target_precompile_headers(WebClient PRIVATE ${PCH_FILES})

target_compile_features(WebClient PRIVATE cxx_std_20)
