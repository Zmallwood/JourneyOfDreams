#pragma once

#include <SDL.h>

namespace zw
{
    using RID = GLuint;
    static auto Ticks = SDL_GetTicks;
}