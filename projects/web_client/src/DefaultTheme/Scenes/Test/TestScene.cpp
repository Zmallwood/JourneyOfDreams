//  Copyright (C) 2024 Andreas Åkerberg

#include "TestScene.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace JourneyOfDreams
{
    TestScene::TestScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage(); 
        m_ridLogo = _<ImageRenderer>().NewImage();
    }

    void TestScene::OnEnter()
    {
        //_<SceneManager>().GoToScene("ServerConnectScene"); 
    }

    void TestScene::UpdateDerived()
    {
    }

    void TestScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f });
    }
}
