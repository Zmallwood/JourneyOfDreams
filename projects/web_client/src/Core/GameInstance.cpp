#include "GameInstance.h"
#include "Engine/Assets/ImageBank.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"

namespace zw
{
    void GameInstance::Run()
    {
        _<Engine>();    // Touch Engine to initialize
        _<ImageBank>(); // Touch ImageBank to initialize

        int simulate_infinite_loop = 1;

        while (true)
        {
            DoOneGameLoopFrame();
        }

        // emscripten_set_main_loop(DoOneGameLoopFrame, -1, simulate_infinite_loop);
    }
}