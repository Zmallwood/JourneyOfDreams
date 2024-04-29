#pragma once

namespace JourneyOfDreams
{
    class Tile;

    class WorldArea
    {
      public:
        WorldArea();
        Size GetSize();
        std::shared_ptr<Tile> GetTile(Point coordinate);
        bool IsValidCoordinate(Point coordinate);
        Point GetRandomCoordinate();
        std::shared_ptr<Tile> GetRandomTile();
        auto &Tiles()
        {
            return m_tiles;
        }

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
    };
}