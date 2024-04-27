#include "IScene.h"
// #include "Core/Engine/GUICore/GUI.h"

namespace zw
{
    IScene::IScene() 
    // : m_gui(std::make_shared<zw::GUI>())
    {
        // m_gui->Initialize();
    }

    void IScene::Update()
    {
        UpdateDerived();
        // m_gui->Update();
    }

    void IScene::Render()
    {
        RenderDerived();
        // m_gui->Render();
    }
}