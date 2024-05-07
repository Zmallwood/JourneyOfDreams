/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* LoginNetRequestScene class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Entered from LoginScene when login button is pressed.
  /// Sends login request to server.
  /////////////////////////////////////////////////
  class LoginNetRequestScene : public IScene {
   public:
    /////////////////////////////////////////////////
    /// Set up GUILabel showing login message.
    /////////////////////////////////////////////////
    LoginNetRequestScene();

    /////////////////////////////////////////////////
    /// Grabs username and password from LoginScene and
    /// sends login request to server.
    /////////////////////////////////////////////////
    void OnEnter() override;
  };
}