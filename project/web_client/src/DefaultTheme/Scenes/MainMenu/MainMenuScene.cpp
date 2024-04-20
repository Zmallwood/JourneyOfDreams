#include "MainMenuScene.h"
#include "Core/Engine/GUICore/GUIButton.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUIPanel.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw
{
    MainMenuScene::MainMenuScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
        GUI()->AddWidget("LoginPanel",
                         std::make_shared<GUIPanel>(RectF{ .x = 0.5f, .y = 0.5f, .w = 0.2f, .h = 0.2f },
                                                    GUIAlign::Center));
        GUI()
            ->GetWidget<GUIPanel>("LoginPanel")
            ->AddWidget("LoginLabel", std::make_shared<GUILabel>(PointF{ 0.0f, 0.0f }, "Login"));
        GUI()
            ->GetWidget<GUIPanel>("LoginPanel")
            ->AddWidget("LoginButton",
                        std::make_shared<GUIButton>(RectF{ 0.0f, 0.1f, 0.1f, 0.05f }, "Login", [] {}));
    }

    void MainMenuScene::UpdateDerived()
    {
    }

    void MainMenuScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f });
    }
}