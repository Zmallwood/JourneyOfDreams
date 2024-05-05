//  Copyright (C) 2024 Andreas Åkerberg

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams {
    class TestScene : public IScene {
      public:
        TestScene();

        void UpdateDerived() override;

        void RenderDerived() override;

        void UpdatePostRender() override;

      private:
        RID m_ridBackground{ 0 };
        RID m_ridLogo{ 0 };
    };
}