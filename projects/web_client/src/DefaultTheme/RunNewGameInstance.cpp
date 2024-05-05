// Copyright (c) 2024 Andreas Åkerberg.

#include "RunNewGameInstance.h"
#include "Core/GameInstance.h"

namespace journey_of_dreams {
    void RunNewGameInstance() {
        GameInstance gameInstance;
        gameInstance.Run();
    }
}