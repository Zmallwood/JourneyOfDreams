// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// fps_counter class declaration.

namespace journey_of_dreams
{
  class FPSCounter {
   public:
    FPSCounter();

    void Update();

    void Render();

   private:
    int m_fps{0};
    int m_framesCount{0};
    int m_ticksLastUpdate{0};
  };
} // namespace journey_of_dreams
