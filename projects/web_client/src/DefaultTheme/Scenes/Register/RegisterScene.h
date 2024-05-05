//  Copyright (C) 2024 Andreas Åkerberg

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams {
    class RegisterScene : public IScene {
      public:
        RegisterScene();

        void OnEnter() override;

        void UpdateDerived() override;

        void RenderDerived() override;

      private:
        bool EnsurePasswordConfirmed();

        RID m_ridBackground{ 0 };
        RID m_ridLogo{ 0 };
    };
}
