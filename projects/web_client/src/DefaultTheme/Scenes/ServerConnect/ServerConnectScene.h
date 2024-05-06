/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* ServerConnectScene class declaration. */

namespace JourneyOfDreams
{
  class ServerConnectScene : public IScene {
   public:
    ServerConnectScene();

    void OnEnter() override;

    void UpdateDerived() override;
  };
}