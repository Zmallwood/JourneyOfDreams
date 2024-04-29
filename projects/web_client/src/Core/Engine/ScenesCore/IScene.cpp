#include "IScene.h"
#include "Core/Engine/GUICore/GUI.h"

namespace JourneyOfDreams
{
    IScene::IScene() 
    : m_gui(std::make_shared<JourneyOfDreams::GUI>())
    {
        m_gui->Initialize();
    }

    void IScene::Update()
    {
        UpdateDerived();
        m_gui->Update();
    }

    void IScene::Render()
    {
        RenderDerived();
        m_gui->Render();
    }
}