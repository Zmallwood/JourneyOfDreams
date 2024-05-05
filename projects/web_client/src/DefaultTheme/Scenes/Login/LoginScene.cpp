// Copyright (c) 2024 Andreas Åkerberg.

#include "LoginScene.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/GUIButton.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUIPanel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace journey_of_dreams {
    LoginScene::LoginScene() {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridLogo = _<ImageRenderer>().NewImage();
        auto loginPanel = GUI()->AddWidget(std::make_shared<GUIPanel>(
            RectF{ .x = 0.5f, .y = 0.5f, .w = 0.3f, .h = 0.3f }, GUIAlign::Center));
        loginPanel->AddWidget(std::make_shared<GUILabel>(PointF{ 0.0f, 0.0f }, "Login"));
        loginPanel->AddWidget(std::make_shared<GUIButton>(RectF{ 0.17f, 0.2f, 0.1f, 0.05f }, "Login", [] {
            _<SceneManager>().GoToScene("LoginNetRequestScene");
        }));
        loginPanel->AddWidget(std::make_shared<GUIButton>(RectF{ 0.014f, 0.2f, 0.1f, 0.05f }, "Register", [] {
            _<SceneManager>().GoToScene("RegisterScene");
        }));
        loginPanel->AddWidget("UsernameTextBox",
                              std::make_shared<GUITextBox>(RectF{ 0.05f, 0.05f, 0.18f, 0.05f }));
        loginPanel->AddWidget(
            "PasswordTextBox",
            std::make_shared<GUITextBox>(RectF{ 0.05f, 0.12f, 0.18f, 0.05f }, Colors::Wheat, true));
    }
    void LoginScene::OnEnter() {
        GUI()->GetWidget<GUITextBox>("UsernameTextBox")->ClearText();
        GUI()->GetWidget<GUITextBox>("PasswordTextBox")->ClearText();
    }
    void LoginScene::UpdateDerived() {
    }
    void LoginScene::RenderDerived() {
        _<ImageRenderer>().DrawImage(m_ridBackground, "DefaultSceneBackground", { 0.0f, 0.0f, 1.0f, 1.0f });
        _<ImageRenderer>().DrawImage(m_ridLogo, "JourneyOfDreamsLogo", { 0.4f, 0.2f, 0.2f, 0.1f });
    }
}
