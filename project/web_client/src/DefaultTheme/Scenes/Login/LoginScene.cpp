#include "LoginScene.h"
#include "Core/Engine/GUICore/GUIButton.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUIPanel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    LoginScene::LoginScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
        auto loginPanel = GUI()->AddWidget(
            "LoginPanel", std::make_shared<GUIPanel>(RectF{ .x = 0.5f, .y = 0.5f, .w = 0.3f, .h = 0.3f },
                                                     GUIAlign::Center));
        loginPanel->AddWidget("LoginLabel", std::make_shared<GUILabel>(PointF{ 0.0f, 0.0f }, "Login"));
        loginPanel->AddWidget("LoginButton",
                              std::make_shared<GUIButton>(RectF{ 0.17f, 0.2f, 0.1f, 0.05f }, "Login",
                                                          [] { _<SceneManager>().GoToScene("Main"); }));
        loginPanel->AddWidget("RegisterButton", std::make_shared<GUIButton>(
                                                    RectF{ 0.014f, 0.2f, 0.1f, 0.05f }, "Register", [] {}));
        loginPanel->AddWidget("UsernameTextBox",
                              std::make_shared<GUITextBox>(RectF{ 0.05f, 0.05f, 0.18f, 0.05f }));
        loginPanel->AddWidget("PasswordTextBox",
                              std::make_shared<GUITextBox>(RectF{ 0.05f, 0.12f, 0.18f, 0.05f }));
    }

    void LoginScene::UpdateDerived()
    {
    }

    void LoginScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f });
    }
}