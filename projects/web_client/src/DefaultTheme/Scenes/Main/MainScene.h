// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// main_scene class declaration.

namespace journey_of_dreams
{
  class MainScene : public IScene {
   public:
    void OnEnter() override;

    void UpdateDerived() override;

    void RenderDerived() override;
  };
} // namespace journey_of_dreams
