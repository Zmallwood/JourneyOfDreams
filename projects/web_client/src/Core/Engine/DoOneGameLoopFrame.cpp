#include "DoOneGameLoopFrame.h"
#include "Engine.h"

namespace JourneyOfDreams
{
    void DoOneGameLoopFrame()
    {
        _<Engine>().Reset();
        _<Engine>().HandleInput();
        _<Engine>().Update();
        _<Engine>().UpdateNet();
        _<Engine>().Render();
        _<Engine>().UpdatePostRender();
        _<Engine>().PresentCanvas();
    }
}
