#pragma once

namespace zw
{
    class Engine
    {
      public:
        Engine();
        void ClearCanvas();
        void Update();
        void Render();
        void PresentCanvas();
    };
}