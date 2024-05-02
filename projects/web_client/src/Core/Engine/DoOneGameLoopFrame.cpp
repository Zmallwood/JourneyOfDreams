#include "DoOneGameLoopFrame.h"
#include "Assets/ImageBank.h"
#include "Core/Test/Tester1.h"
#include "Core/Test/Tester2.h"
#include "Core/Test/Tester3.h"
#include "Engine.h"
#include "Graphics/Graphics.h"

namespace JourneyOfDreams
{
    void DoOneGameLoopFrame()
    {
        _<Tester1>().Render();
        _<Tester1>().Stop();

        _<Tester2>().Render();
        _<Tester1>().Stop();

        _<Graphics>();     // Touch Graphics to initialize it
        _<ImageBank>(); // Touch ImageBank to initialize

        _<Tester3>().Render();

        // _<Engine>(); // Touch Engine to initialize

        // _<Engine>().Reset();
        // _<Engine>().HandleInput();
        // _<Engine>().Update();
        // _<Engine>().UpdateNet();
        // _<Engine>().Render();
        // _<Engine>().UpdatePostRender();
        // _<Engine>().PresentCanvas();
    }
}
