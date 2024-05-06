/* Copyright (c) 2024 Andreas Åkerberg. */

#include "FPSCounter.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/GUILabel.h"
#include "DefaultTheme/Scenes/Main/MainScene.h"

/* FPSCounter class implementation. */

namespace JourneyOfDreams
{
  FPSCounter::FPSCounter() {
    _<MainScene>().GUI()->AddWidget(
        "FPSCounterLabel",
        std::make_shared<GUILabel>(PointF{.x = 0.85f, .y = 0.0f}, "FPS: 0"));
  }

  void FPSCounter::Update() {
    m_framesCount++;

    unsigned int ticks{Ticks()};
    if (ticks - m_ticksLastUpdate >= 1000) {
      m_fps = m_framesCount;
      m_framesCount = 0;
      m_ticksLastUpdate = ticks;
    }
  }

  void FPSCounter::Render() {
    _<MainScene>()
        .GUI()
        ->GetWidget<GUILabel>("FPSCounterLabel")
        ->SetText(
            std::make_shared<std::string>("FPS: " + std::to_string(m_fps)));
  }
}