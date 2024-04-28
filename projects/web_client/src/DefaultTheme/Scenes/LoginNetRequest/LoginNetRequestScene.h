#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class LoginNetRequestScene : public IScene
    {
      public:
        LoginNetRequestScene(zw::Engine &engine);

        void OnEnter() override;
    };
}
