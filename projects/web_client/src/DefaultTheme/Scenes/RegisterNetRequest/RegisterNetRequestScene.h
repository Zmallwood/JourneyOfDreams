#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class RegisterNetRequestScene : public IScene
    {
      public:
        RegisterNetRequestScene(zw::Engine &engine);

        void OnEnter() override;
    };
}
