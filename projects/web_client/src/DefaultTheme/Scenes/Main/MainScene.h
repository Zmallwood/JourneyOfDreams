/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* MainScene class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Main scene of the game where the game is played.
  /////////////////////////////////////////////////
  class MainScene : public IScene {
   public:
    /////////////////////////////////////////////////
    /// Read world data from file, position player
    /// and initialize world view.
    /////////////////////////////////////////////////
    void OnEnter() override;

    /////////////////////////////////////////////////
    /// Update all components related to this scene.
    /////////////////////////////////////////////////
    void UpdateDerived() override;

    /////////////////////////////////////////////////
    /// Render world view and fps counter.
    /////////////////////////////////////////////////
    void RenderDerived() override;
  };
}