#pragma once

namespace zw
{
    class WorldArea;

    class World
    {
      public:
        World();
        auto WorldArea()
        {
            return m_worldArea;
        }

      private:
        std::shared_ptr<zw::WorldArea> m_worldArea;
    };
}