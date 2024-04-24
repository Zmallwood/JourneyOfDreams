#pragma once
#include <SDL.h>

namespace zw
{
    /// Render ID
    using RID = GLuint;

    /// Ticks elapsed since game start
    static auto Ticks = SDL_GetTicks;
}
