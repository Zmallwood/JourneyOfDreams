#pragma once

namespace zw
{
    class Engine
    {
      public:
        Engine();
        void ClearCanvas();
        void HandleInput();
        void Update();
        void Render();
        void PresentCanvas();
    };
}