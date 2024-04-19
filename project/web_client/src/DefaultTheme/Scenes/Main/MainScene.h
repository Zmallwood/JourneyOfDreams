#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class MainScene : public IScene
    {
      public:
        void UpdateDerived() override;
        void RenderDerived() override;
    };
}