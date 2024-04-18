project(Game2Emscripten)
cmake_minimum_required(VERSION 3.22)

#set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s EXPORTED_FUNCTIONS=\"[  '_main']\" -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 --use-preload-plugins -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]'")

add_definitions()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../../bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})

if(TRUE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} " )
endif()

set (OGRE_LIBRARIES /home/andreas/SourceBuild/ogre/OgreMain)

include_directories(${PROJECT_SOURCE_DIR}/Samples/Character/include)
add_executable(Server src/Main.cpp src/WebsocketServer.cpp)
target_include_directories(Server PUBLIC external)

# Compile jsoncpp from source
add_library(jsoncpp STATIC ${PROJECT_SOURCE_DIR}/external/jsoncpp.cpp)

target_link_libraries(Server jsoncpp)