#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class IntroScene : public IScene
    {
      public:
        IntroScene();
        void UpdateDerived() override;
        void RenderDerived() override;

      private:
        RID m_ridBackground{ 0 };
        RID m_ridLogo{ 0 };
        RID m_startText {};
    };
}