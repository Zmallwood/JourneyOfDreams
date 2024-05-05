// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

namespace journey_of_dreams {
    class LoginNetRequestScene : public IScene {
      public:
        LoginNetRequestScene();

        void OnEnter() override;
    };
}
