#include "MainMenuScene.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw
{
    MainMenuScene::MainMenuScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
    }

    void MainMenuScene::UpdateDerived()
    {
    }

    void MainMenuScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f },
                                     { 1.0f, 1.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f },
                                     { 1.0f, 1.0f, 1.0f, 1.0f });
    }
}