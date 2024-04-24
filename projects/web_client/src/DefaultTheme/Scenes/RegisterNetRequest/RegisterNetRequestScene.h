#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class RegisterNetRequestScene : public IScene
    {
      public:
        RegisterNetRequestScene();

        void OnEnter() override;
    };
}
