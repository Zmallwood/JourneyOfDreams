#pragma once

namespace zw
{
    class Tile;

    class WorldArea
    {
      public:
        WorldArea();
        auto &Tiles()
        {
            return m_tiles;
        }

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
    };
}