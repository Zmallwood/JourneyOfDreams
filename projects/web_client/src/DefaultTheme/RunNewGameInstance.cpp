// Copyright (c) 2024 Andreas Åkerberg.

#include "RunNewGameInstance.h"
#include "Core/GameInstance.h"

// run_new_game_instance function implementation.

namespace journey_of_dreams
{
  void
  RunNewGameInstance() {
    GameInstance gameInstance;
    gameInstance.Run();
  }
} // namespace journey_of_dreams