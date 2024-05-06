/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GameInstance.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"

// game_instance class implementation.

namespace JourneyOfDreams
{
  void GameInstance::Run() {
    int simulate_infinite_loop = 1;

    emscripten_set_main_loop(DoOneGameLoopFrame, -1, simulate_infinite_loop);
  }
}