#include "GameInstance.h"
#include "Engine/DoOneGameLoopFrame.h"
#include "Engine/Engine.h"

namespace JourneyOfDreams
{
    void GameInstance::Run()
    {
        int simulate_infinite_loop = 1;

        emscripten_set_main_loop(DoOneGameLoopFrame, -1, simulate_infinite_loop);
    }
}