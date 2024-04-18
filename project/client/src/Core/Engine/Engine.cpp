#include "Engine.h"
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
    }

    void Engine::ClearCanvas()
    {
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
    }

    void Engine::PresentCanvas()
    {
        _<Graphics>().PresentCanvas();
    }
}