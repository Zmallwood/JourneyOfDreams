#pragma once

namespace JourneyOfDreams
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