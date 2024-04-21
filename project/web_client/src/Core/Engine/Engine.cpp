#include "Engine.h"
#include "Cursor/Cursor.h"
#include "Graphics/Graphics.h"
#include "Net/Net.h"
#include "PollEvents.h"
#include "ScenesCore/SceneManager.h"

namespace zw
{
    Engine::Engine()
    {
        _<Net>();          // Touch Net to initialize it
        _<Graphics>();     // Touch Graphics to initialize it
        _<SceneManager>(); // Touch SceneManager to initialize it
        _<Cursor>();       // Touch Cursor to initialize it
    }

    void Engine::Reset()
    {
        _<Cursor>().ResetStyle();
        _<Graphics>().ClearCanvas();
    }

    void Engine::HandleInput()
    {
        PollEvents();
    }

    void Engine::Update()
    {
        _<SceneManager>().UpdateCurrentScene();
    }

    void Engine::Render()
    {
        _<SceneManager>().RenderCurrentScene();
        _<Cursor>().Render();
    }

    void Engine::PresentCanvas()
    {
        _<Graphics>().PresentCanvas();
    }
}