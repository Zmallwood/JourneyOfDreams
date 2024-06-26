/* Copyright (c) 2024 Andreas Åkerberg. */

#include "ServerConnectScene.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "Core/Engine/Net/NetClient.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

/* ServerConnectScene class implementation. */

namespace JourneyOfDreams
{
  ServerConnectScene::ServerConnectScene() {
    GUI()->AddWidget(std::make_shared<GUILabel>(PointF{.x = 0.5f, .y = 0.5f},
                                                "Connecting to server...",
                                                GUIAlign::Center));
  }

  void ServerConnectScene::OnEnter() {
    _<NetClient>().BeginEstablishConnection();
  }

  void ServerConnectScene::UpdateDerived() {
    if (_<NetClient>().Connected()) {
      _<SceneManager>().GoToScene("LoginScene");
    }
  }
}