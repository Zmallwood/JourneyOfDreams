// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace JourneyOfDreams {
    class FPSCounter {
      public:
        FPSCounter();

        void Update();

        void Render();

      private:
        int m_fps{ 0 };
        int m_framesCount{ 0 };
        int m_ticksLastUpdate{ 0 };
    };
}
