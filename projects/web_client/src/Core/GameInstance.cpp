/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GameInstance.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"

/* GameInstance class implementation. */

namespace JourneyOfDreams
{
  void GameInstance::Run() {
    int simulateInfiniteLoop{1};
    emscripten_set_main_loop(DoOneGameLoopFrame, -1, simulateInfiniteLoop);
  }
}