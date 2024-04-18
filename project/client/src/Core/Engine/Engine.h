#pragma once

namespace zw
{
    class Engine
    {
      public:
        void ClearCanvas();
        void Update();
        void Render();
        void PresentCanvas();
    };
}