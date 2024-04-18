#pragma once

namespace zw
{
    class GameProperties
    {
      public:
        auto CanvasSize()
        {
            return m_canvasSize;
        }
        auto DefaultClearColor()
        {
            return m_defaultClearColor;
        }

      private:
        Size m_canvasSize{ 1000, 600 };
        ColorF m_defaultClearColor{ 0.0f, 0.5f, 1.0f };
    };
}