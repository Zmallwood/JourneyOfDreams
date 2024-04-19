#pragma once

#define GL_GLEXT_PROTOTYPES 1

#include <iostream>
#include <memory>
#include <map>
#include <utility>
#include <set>
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengles2.h>

#include <emscripten/websocket.h>
#include <emscripten.h>

#include "Common/Singleton.h"
#include "Common/SDLDeleter.h"
#include "Common/Utilities.h"

#include "../../shared/matter/src/Size.h"
#include "../../shared/matter/src/ColorF.h"