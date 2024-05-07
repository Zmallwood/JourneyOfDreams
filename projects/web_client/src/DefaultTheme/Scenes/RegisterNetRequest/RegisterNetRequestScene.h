/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* RegisterNetRequestScene class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Does the network request for registration of
  /// new account.
  /////////////////////////////////////////////////
  class RegisterNetRequestScene : public IScene {
   public:
    /////////////////////////////////////////////////
    /// Set up GUILabel showing registration message.
    /////////////////////////////////////////////////
    RegisterNetRequestScene();

    /////////////////////////////////////////////////
    /// Grabs the registration data from the RegisterScene
    /// and sends it to the server.
    /////////////////////////////////////////////////
    void OnEnter() override;
  };
}