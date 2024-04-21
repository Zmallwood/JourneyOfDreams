#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class LoginRequestScene : public IScene
    {
      public:
        LoginRequestScene();
        void OnEnter() override;
    };
}
