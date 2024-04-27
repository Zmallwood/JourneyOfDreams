#pragma once

namespace zw
{
    class GlobalProperties
    {
      public:
        auto WorldAreaSize()
        {
            return m_worldAreaSize;
        }

      private:
        Size m_worldAreaSize{ 100, 100 };
    };
}