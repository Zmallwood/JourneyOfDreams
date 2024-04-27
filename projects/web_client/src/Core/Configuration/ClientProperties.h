#pragma once

namespace zw
{
    class ClientProperties
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
        auto NumGridRows()
        {
            return m_numGridRows;
        }

      private:
        Size m_canvasSize{ 1000, 600 };
        ColorF m_defaultClearColor{ 0.0f, 0.5f, 1.0f };
        int m_numGridRows = 11;
    };
}