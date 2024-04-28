#pragma once

#include "Core/Engine/ScenesCore/IScene.h"

namespace zw
{
    class ServerConnectScene : public IScene
    {
      public:
        ServerConnectScene(zw::Engine &engine);

        void OnEnter() override;

        void UpdateDerived() override;
    };
}
