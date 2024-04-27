#include "WorldArea.h"
#include "Tile.h"
#include "configuration/src/GlobalProperties.h"

namespace zw
{
    WorldArea::WorldArea()
    {
        auto width = _<GlobalProperties>().WorldAreaSize().w;
        auto height = _<GlobalProperties>().WorldAreaSize().h;

        for (auto x = 0; x < width; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());
            for (auto y = 0; y < height; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    Size WorldArea::GetSize()
    {
        auto width = m_tiles.size();
        auto height = width > 0 ? m_tiles.at(0).size() : 0;

        return { static_cast<int>(width), static_cast<int>(height) };
    }

    std::shared_ptr<Tile> WorldArea::GetTile(Point coordinate)
    {
        if (IsValidCoordinate(coordinate))
            return m_tiles.at(coordinate.x).at(coordinate.y);
        else
            return nullptr;
    }

    bool WorldArea::IsValidCoordinate(Point coordinate)
    {
        auto size = GetSize();
        return coordinate.x >= 0 && coordinate.y >= 0 && coordinate.x < size.w && coordinate.y < size.h;
    }

    Point WorldArea::GetRandomCoordinate()
    {
        auto size = GetSize();
        return { .x = rand() % size.w, .y = rand() % size.h };
    }

    std::shared_ptr<Tile> WorldArea::GetRandomTile()
    {
        return GetTile(GetRandomCoordinate());
    }
}