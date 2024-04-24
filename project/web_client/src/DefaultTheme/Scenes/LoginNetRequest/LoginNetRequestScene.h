#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class LoginNetRequestScene : public IScene
    {
      public:
        LoginNetRequestScene();

        void OnEnter() override;
    };
}
