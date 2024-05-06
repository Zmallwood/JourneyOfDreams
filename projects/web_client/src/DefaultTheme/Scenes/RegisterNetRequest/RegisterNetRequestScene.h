// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// register_net_request_scene class declaration.

namespace JourneyOfDreams
{
  class RegisterNetRequestScene : public IScene {
   public:
    RegisterNetRequestScene();

    void OnEnter() override;
  };
} // namespace JourneyOfDreams
