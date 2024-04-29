#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams
{
    class ServerConnectScene : public IScene
    {
      public:
        ServerConnectScene();

        void OnEnter() override;

        void UpdateDerived() override;
    };
}
