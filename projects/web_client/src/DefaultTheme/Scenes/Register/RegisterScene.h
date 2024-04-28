#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class RegisterScene : public IScene
    {
      public:
        RegisterScene(zw::Engine &engine);

        void OnEnter() override;

        void UpdateDerived() override;

        void RenderDerived() override;

      private:
        bool EnsurePasswordConfirmed();

        RID m_ridBackground{ 0 };
        RID m_ridLogo{ 0 };
    };
}
