/* Copyright (c) 2024 Andreas Åkerberg. */

#include "DoOneGameLoopFrame.h"
#include "Assets/ImageBank.h"
#include "Core/Tests/Test1.h"
#include "Core/Tests/Test2.h"
#include "Core/Tests/Test3.h"
#include "Development/DeveloperSettings.h"
#include "Engine.h"
#include "Graphics/Graphics.h"

// do_one_game_loop_frame function implementation.

namespace JourneyOfDreams
{
  void DoOneGameLoopFrame() {
#if defined(DEV_TEST_MODE)
    _<Test1>().Render();
    //_<Test1>().Stop();

    //_<Test2>().Render();
    //_<Test1>().Stop();

    //_<Graphics>();  // Touch Graphics to initialize it
    //_<ImageBank>(); // Touch ImageBank to initialize

    //_<Test3>().Render();
    //_<Test3>().Stop();
#else
    _<Graphics>();  // Touch Graphics to initialize it
    _<ImageBank>(); // Touch ImageBank to initialize
    _<Engine>();    // Touch Engine to initialize

    _<Engine>().Reset();
    _<Engine>().HandleInput();
    _<Engine>().Update();
    _<Engine>().UpdateNet();
    _<Engine>().Render();
    _<Engine>().UpdatePostRender();
    _<Engine>().PresentCanvas();
#endif
  }
}