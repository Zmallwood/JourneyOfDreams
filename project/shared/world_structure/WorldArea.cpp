#include "WorldArea.h"
#include "Core/Configuration/GameProperties.h"
#include "Tile.h"

namespace zw
{
    WorldArea::WorldArea()
    {
        auto width = _<GameProperties>().WorldAreaSize().w;
        auto height = _<GameProperties>().WorldAreaSize().h;

        for (auto x = 0; x < width; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());
            for (auto y = 0; y < height; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }
}