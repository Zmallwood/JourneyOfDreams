/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

/* LoginScene class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Scene showing login panel to login to account.
  /////////////////////////////////////////////////
  class LoginScene : public IScene {
   public:
    /////////////////////////////////////////////////
    /// Allocate graphics resources and sets up GUI components.
    /////////////////////////////////////////////////
    LoginScene();

    /////////////////////////////////////////////////
    /// Clear text fields on enter.
    /////////////////////////////////////////////////
    void OnEnter() override;

    /////////////////////////////////////////////////
    /// Does nothing.
    /////////////////////////////////////////////////
    void UpdateDerived() override;

    /////////////////////////////////////////////////
    /// Draw background and logo images to canvas.
    /////////////////////////////////////////////////
    void RenderDerived() override;

   private:
    RID m_ridBackground{0};
    RID m_ridLogo{0};
  };
}