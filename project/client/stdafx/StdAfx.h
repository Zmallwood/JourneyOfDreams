#pragma once

#define GL_GLEXT_PROTOTYPES 1

#include <iostream>
#include <memory>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengles2.h>

#include <emscripten/websocket.h>
#include <emscripten.h>

#include "Common/Singleton.h"
#include "Common/SDLDeleter.h"