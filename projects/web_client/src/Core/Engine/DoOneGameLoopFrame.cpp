#include "DoOneGameLoopFrame.h"
#include "Engine.h"
#include "Core/Test/Tester.h"

namespace JourneyOfDreams
{
    void DoOneGameLoopFrame()
    {
        _<Tester>().Render();

        // _<Engine>(); // Touch Engine to initialize
        // _<ImageBank>(); // Touch ImageBank to initialize


        // _<Engine>().Reset();
        // _<Engine>().HandleInput();
        // _<Engine>().Update();
        // _<Engine>().UpdateNet();
        // _<Engine>().Render();
        // _<Engine>().UpdatePostRender();
        // _<Engine>().PresentCanvas();
    }
}
