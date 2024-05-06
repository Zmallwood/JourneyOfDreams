// Copyright (c) 2024 Andreas Åkerberg.

#include "RegisterNetRequestScene.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/GUICore/GUITextBox.h"
#include "Core/Engine/Net/NetClient.h"
#include "Core/Engine/ScenesCore/SceneManager.h"
#include "DefaultTheme/Scenes/Register/RegisterScene.h"

// register_net_request_scene class implementation.

namespace JourneyOfDreams
{
  RegisterNetRequestScene::RegisterNetRequestScene() {
    GUI()->AddWidget("RegisterAccountLabel",
                     std::make_shared<GUILabel>(PointF{.x = 0.5f, .y = 0.5f},
                                                "Registering account...",
                                                GUIAlign::Center));
  }

  void
  RegisterNetRequestScene::OnEnter() {
    auto username = _<RegisterScene>()
                        .GUI()
                        ->GetWidget<GUITextBox>("UsernameTextBox")
                        ->GetText();
    auto password = _<RegisterScene>()
                        .GUI()
                        ->GetWidget<GUITextBox>("PasswordTextBox")
                        ->GetText();

    SHA256 sha;

    sha.update(password);
    std::array<uint8_t, 32> digestPassword = sha.digest();

    auto passwordHash = SHA256::toString(digestPassword);

    std::map<std::string, std::string> data;
    data.insert({"Username", username});
    data.insert({"PasswordHash", passwordHash});

    _<NetClient>().Send(data);
  }
} // namespace JourneyOfDreams
