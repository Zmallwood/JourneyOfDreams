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
    };
}