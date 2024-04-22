#include "RegisterScene.h"
#include "Core/Engine/GUICore/GUIButton.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUIPanel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    RegisterScene::RegisterScene()
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
        auto registerPanel = GUI()->AddWidget(
            "RegisterPanel", std::make_shared<GUIPanel>(RectF{ .x = 0.5f, .y = 0.5f, .w = 0.35f, .h = 0.4f },
                                                        GUIAlign::Center));
        registerPanel->AddWidget("RegisterLabel",
                                 std::make_shared<GUILabel>(PointF{ 0.0f, 0.0f }, "Register"));
        registerPanel->AddWidget("RegisterButton", std::make_shared<GUIButton>(
                                                       RectF{ 0.22f, 0.3f, 0.1f, 0.05f }, "Register", [] {}));
        registerPanel->AddWidget(
            "BackButton", std::make_shared<GUIButton>(RectF{ 0.014f, 0.3f, 0.1f, 0.05f }, "Back",
                                                      [] { _<SceneManager>().GoToScene("LoginScene"); }));
        registerPanel->AddWidget("UsernameLabel", std::make_shared<GUILabel>(PointF{ 0.02f, 0.05f },
                                                                             "Username", Colors::Silver));
        registerPanel->AddWidget("UsernameTextBox",
                                 std::make_shared<GUITextBox>(RectF{ 0.15f, 0.05f, 0.18f, 0.05f }));
        registerPanel->AddWidget("PasswordLabel", std::make_shared<GUILabel>(PointF{ 0.02f, 0.12f },
                                                                             "Password", Colors::Silver));
        registerPanel->AddWidget(
            "PasswordTextBox",
            std::make_shared<GUITextBox>(RectF{ 0.15f, 0.12f, 0.18f, 0.05f }, Colors::Wheat, true));
        registerPanel->AddWidget(
            "ConfirmPasswordLabel",
            std::make_shared<GUILabel>(PointF{ 0.02f, 0.19f }, "Confirm", Colors::Silver));
        registerPanel->AddWidget(
            "ConfirmPasswordTextBox",
            std::make_shared<GUITextBox>(RectF{ 0.15f, 0.19f, 0.18f, 0.05f }, Colors::Wheat, true));
    }

    void RegisterScene::OnEnter()
    {
        GUI()->GetWidget<GUITextBox>("UsernameTextBox")->ClearText();
        GUI()->GetWidget<GUITextBox>("PasswordTextBox")->ClearText();
        GUI()->GetWidget<GUITextBox>("ConfirmPasswordTextBox")->ClearText();
    }

    void RegisterScene::UpdateDerived()
    {
    }

    void RegisterScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f });
    }
}