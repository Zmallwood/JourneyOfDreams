// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "Core/Engine/ScenesCore/IScene.h"

namespace JourneyOfDreams {
    class MainScene : public IScene {
      public:
        void OnEnter() override;

        void UpdateDerived() override;

        void RenderDerived() override;
    };
}
