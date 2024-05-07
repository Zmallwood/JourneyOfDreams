/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* ServerConnectScene class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Scene entered before LoginScene, where the
  /// client connects to the server.
  /////////////////////////////////////////////////
  class ServerConnectScene : public IScene {
   public:
    /////////////////////////////////////////////////
    /// Set up GUILabel showing connecting message.
    /////////////////////////////////////////////////
    ServerConnectScene();

    /////////////////////////////////////////////////
    /// Begin establish connection to server.
    /////////////////////////////////////////////////
    void OnEnter() override;

    /////////////////////////////////////////////////
    /// If connection is established, navigates to LoginScene.
    /////////////////////////////////////////////////
    void UpdateDerived() override;
  };
}