/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* RegisterNetRequestScene class declaration. */

namespace JourneyOfDreams
{
  class RegisterNetRequestScene : public IScene {
   public:
    RegisterNetRequestScene();

    void OnEnter() override;
  };
}