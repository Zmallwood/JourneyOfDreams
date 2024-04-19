#include "DoOneGameLoopFrame.h"
#include "Engine.h"

namespace zw
{
    void DoOneGameLoopFrame()
    {
        _<Engine>().ClearCanvas();
        _<Engine>().HandleInput();
        _<Engine>().Update();
        _<Engine>().Render();
        _<Engine>().PresentCanvas();
    }
}