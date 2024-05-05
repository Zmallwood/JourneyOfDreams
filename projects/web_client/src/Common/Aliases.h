//
//  Copyright (C) 2024 Andreas Åkerberg.
//
#pragma once
#include <SDL2/SDL.h>
//
//  Aliases creation.
//
namespace JourneyOfDreams
{
   /////////////////////////////////////////////////
   /// Resource ID
   /////////////////////////////////////////////////
   using RID = GLuint;
   /////////////////////////////////////////////////
   /// Ticks elapsed since game start
   ///
   /// \return Number of ticks since game start.
   /////////////////////////////////////////////////
   static auto Ticks = SDL_GetTicks;
} // namespace JourneyOfDreams
