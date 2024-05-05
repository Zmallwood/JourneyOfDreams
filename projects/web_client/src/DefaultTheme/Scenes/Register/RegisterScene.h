// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// register_scene class declaration.

namespace journey_of_dreams
{
  class RegisterScene : public IScene {
   public:
    RegisterScene();

    void OnEnter() override;

    void UpdateDerived() override;

    void RenderDerived() override;

   private:
    bool EnsurePasswordConfirmed();

    RID m_ridBackground{0};
    RID m_ridLogo{0};
  };
} // namespace journey_of_dreams
