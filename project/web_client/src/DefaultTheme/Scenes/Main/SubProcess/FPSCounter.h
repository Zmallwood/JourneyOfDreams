#pragma once

namespace zw
{
    class FPSCounter
    {
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