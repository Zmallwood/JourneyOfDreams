#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams
{
    class RegisterNetRequestScene : public IScene
    {
      public:
        RegisterNetRequestScene();

        void OnEnter() override;
    };
}
