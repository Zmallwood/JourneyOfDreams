#include "Engine.h"
// #include "Assets/ImageBank.h"
// #include "Cursor/Cursor.h"
// #include "Graphics/Graphics.h"
// #include "Net/NetClient.h"
// #include "PollEvents.h"
// #include "Rendering/TextRendering/TextRenderer.h"
// #include "ScenesCore/SceneManager.h"

namespace zw
{
    Engine::Engine()
        // : m_graphics(std::make_shared<zw::Graphics>(*this)),
        // m_imageBank(std::make_shared<zw::ImageBank>()),
        //   m_netClient(std::make_shared<zw::NetClient>()),
        //   m_sceneManager(std::make_shared<zw::SceneManager>(*this)),
        //   m_cursor(std::make_shared<zw::Cursor>(*this)),
        //   m_textRenderer(std::make_shared<zw::TextRenderer>(*this))
    {
        srand(time(0));

        // m_graphics->Init();
        // m_imageBank->LoadImages();
        // m_sceneManager->Init();
    }

    void Engine::Reset()
    {
        // m_cursor->ResetStyle();
        // m_graphics->ClearCanvas();
    }

    void Engine::HandleInput()
    {
        // PollEvents();
    }

    void Engine::Update()
    {
        // m_sceneManager->UpdateCurrentScene();
    }

    void Engine::UpdateNet()
    {
        // m_netClient->Update();
    }

    void Engine::Render()
    {
        // m_sceneManager->RenderCurrentScene();
        // m_cursor->Render();
    }

    void Engine::UpdatePostRender()
    {
        // m_sceneManager->UpdatePostRenderCurrentScene();
    }

    void Engine::PresentCanvas()
    {
        // m_graphics->PresentCanvas();
    }
}
