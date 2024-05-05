// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include <SDL2/SDL.h>

// Aliases creation.

namespace journey_of_dreams
{
   /////////////////////////////////////////////////
   /// Resource ID.
   /////////////////////////////////////////////////
   using RID = GLuint;

   /////////////////////////////////////////////////
   /// Ticks elapsed since game start.
   ///
   /// \return Number of ticks since game start.
   /////////////////////////////////////////////////
   static auto Ticks = SDL_GetTicks;
} // namespace journey_of_dreams
