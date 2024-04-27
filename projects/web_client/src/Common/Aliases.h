#pragma once
#include <SDL2/SDL.h>

namespace zw
{
    /// Resource ID
    using RID = GLuint;

    /// Ticks elapsed since game start
    static auto Ticks = SDL_GetTicks;
}
    