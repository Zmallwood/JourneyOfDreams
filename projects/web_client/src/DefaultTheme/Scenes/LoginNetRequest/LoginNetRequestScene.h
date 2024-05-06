/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* LoginNetRequestScene class declaration. */

namespace JourneyOfDreams
{
  class LoginNetRequestScene : public IScene {
   public:
    LoginNetRequestScene();

    void OnEnter() override;
  };
}