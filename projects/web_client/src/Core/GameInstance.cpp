#include "GameInstance.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"
// #include "Engine/Assets/ImageBank.h"

namespace zw
{
    void GameInstance::Run()
    {
        Engine engine;

        int simulate_infinite_loop = 1;

        emscripten_set_main_loop_arg(DoOneGameLoopFrame, &engine, -1, simulate_infinite_loop);
    }
}