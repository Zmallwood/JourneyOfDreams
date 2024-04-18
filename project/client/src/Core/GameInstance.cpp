#include "GameInstance.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"

namespace zw
{
    void GameInstance::Run()
    {
        _<Engine>(); // Touch Engine to initialize

        int simulate_infinite_loop = 1;

        emscripten_set_main_loop(DoOneGameLoopFrame, -1, simulate_infinite_loop);
    }
}