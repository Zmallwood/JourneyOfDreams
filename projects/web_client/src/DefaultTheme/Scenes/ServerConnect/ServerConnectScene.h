// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// server_connect_scene class declaration.

namespace journey_of_dreams
{
  class ServerConnectScene : public IScene {
   public:
    ServerConnectScene();

    void OnEnter() override;

    void UpdateDerived() override;
  };
} // namespace journey_of_dreams
