#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams
{
    class LoginNetRequestScene : public IScene
    {
      public:
        LoginNetRequestScene();

        void OnEnter() override;
    };
}
