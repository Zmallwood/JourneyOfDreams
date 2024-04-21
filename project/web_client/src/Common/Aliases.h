#pragma once

#include <SDL2/SDL.h>

namespace zw
{
    using RID = GLuint;
    static auto Ticks = SDL_GetTicks;
}