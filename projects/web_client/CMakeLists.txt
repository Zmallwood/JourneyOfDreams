project(WebClient)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_EXECUTABLE_SUFFIX ".html")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2 -s NO_DISABLE_EXCEPTION_CATCHING")
set(CMAKE_EXE_LINKER_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}/resources@/ -s STB_IMAGE -s USE_SDL=2 -s MAX_WEBGL_VERSION=2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='[\"png\"]' -s USE_SDL_TTF=2 --shell-file ${CMAKE_SOURCE_DIR}/html/shell_minimal.html")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../bin_web_client)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/")

include_directories(${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/../shared)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SRC_FILES_EXTERNAL ${PROJECT_SOURCE_DIR}/external/*.cpp)
file(GLOB_RECURSE SRC_FILES_SHARED ${PROJECT_SOURCE_DIR}/../shared/*.cpp)
add_executable(WebClient ${SRC_FILES} ${SRC_FILES_EXTERNAL} ${SRC_FILES_SHARED})

# add_executable(WebClient
#   src/Main.cpp
#   src/DefaultTheme/RunNewGameInstance.cpp
#   src/Core/GameInstance.cpp
#   src/Core/Engine/DoOneGameLoopFrame.cpp
#   src/Core/Engine/Engine.cpp
#   src/Core/Engine/Assets/ImageBank.cpp
#   src/Core/Engine/Net/NetClient.cpp
#   src/Core/Engine/Graphics/Graphics.cpp
#   src/Core/Engine/ScenesCore/SceneManager.cpp
#   src/Core/Engine/Cursor/Cursor.cpp
#   src/Core/Engine/PollEvents.cpp
#   src/Common/Utilities.cpp
#   ../shared/common/src/Hash.cpp
#   src/Core/Configuration/ClientProperties.cpp
#   src/Common/SDLDeleter.cpp
#   src/DefaultTheme/Scenes/ServerConnect/ServerConnectScene.cpp
#   src/Core/Engine/Net/NetworkConnection.cpp
#   src/DefaultTheme/Scenes/Login/LoginScene.cpp
#   src/DefaultTheme/Scenes/LoginNetRequest/LoginNetRequestScene.cpp
#   src/DefaultTheme/Scenes/Register/RegisterScene.cpp
#   src/DefaultTheme/Scenes/RegisterNetRequest/RegisterNetRequestScene.cpp
# )

target_link_libraries(WebClient websocket)
set(PCH_FILES
    "stdafx/StdAfx.h"
)
target_precompile_headers(WebClient PRIVATE ${PCH_FILES})

target_compile_features(WebClient PRIVATE cxx_std_20)
