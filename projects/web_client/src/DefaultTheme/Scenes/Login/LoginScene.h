/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// login_scene class declaration.

namespace JourneyOfDreams
{
  class LoginScene : public IScene {
   public:
    LoginScene();

    void OnEnter() override;

    void UpdateDerived() override;

    void RenderDerived() override;

   private:
    RID m_ridBackground{0};
    RID m_ridLogo{0};
  };
}