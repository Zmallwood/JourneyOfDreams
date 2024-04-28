#include "DoOneGameLoopFrame.h"
#include "Engine.h"

namespace zw
{
    void DoOneGameLoopFrame(void * data)
    {
        auto engine = static_cast<Engine*>(data);

        engine->Reset();
        engine->HandleInput();
        engine->Update();
        engine->UpdateNet();
        engine->Render();
        engine->UpdatePostRender();
        engine->PresentCanvas();
    }
}
