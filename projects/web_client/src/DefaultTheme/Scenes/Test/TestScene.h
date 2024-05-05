// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

// test_scene class declaration.

namespace journey_of_dreams
{
  class TestScene : public IScene {
   public:
    TestScene();

    void UpdateDerived() override;

    void RenderDerived() override;

    void UpdatePostRender() override;

   private:
    RID m_ridBackground{0};
    RID m_ridLogo{0};
  };
} // namespace journey_of_dreams