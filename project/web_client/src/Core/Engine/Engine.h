#pragma once

namespace zw
{
    class Engine
    {
      public:
        Engine();
        void Reset();
        void HandleInput();
        void Update();
        void Render();
        void PresentCanvas();
    };
}