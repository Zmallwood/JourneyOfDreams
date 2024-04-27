#include "WorldView.h"
#include "Core/Configuration/ClientProperties.h"
#include "Core/Engine/CoreGameObjects/Player.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "world_structure/src/Tile.h"
#include "world_structure/src/World.h"
#include "world_structure/src/WorldArea.h"

namespace zw
{
    WorldView::WorldView() : m_ridsTiles(std::make_shared<std::vector<std::vector<RID>>>())
    {
        auto gridSize = _<ClientProperties>().GridSize();

        for (auto x = 0; x < gridSize; x++)
        {
            m_ridsTiles->push_back(std::vector<RID>());
            for (auto y = 0; y < gridSize; y++)
            {
                m_ridsTiles->at(x).push_back(_<ImageRenderer>().NewImage());
            }
        }

        m_ridPlayer = _<ImageRenderer>().NewImage();
    }

    void WorldView::Update()
    {
    }

    void WorldView::Render()
    {
        auto gridSize = _<ClientProperties>().GridSize();

        auto worldArea = _<World>().WorldArea();
        auto &player = _<Player>();
        auto tileHeight = 1.0f / gridSize;
        auto tileWidth = ConvertHeightToWidth(tileHeight);
        for (auto y = 0; y < gridSize; y++)
        {
            for (auto x = 0; x < gridSize; x++)
            {
                auto mapX = player.GetX() - (gridSize - 1) / 2 + x;
                auto mapY = player.GetY() - (gridSize - 1) / 2 + y;

                if (mapX < 0 || mapY < 0 || mapX >= worldArea->GetSize().w || mapY >= worldArea->GetSize().h)
                {
                    continue;
                }

                auto tile = worldArea->GetTile({ .x = mapX, .y = mapY });
                auto dest = RectF{ x * tileWidth, y * tileHeight, tileWidth, tileHeight };
                std::string groundImage;

                if (tile->Ground() == Hash("GroundGrass"))
                {
                    groundImage = "GroundGrass";
                }
                else if (tile->Ground() == Hash("GroundWater"))
                {
                    groundImage = "GroundWater";
                }

                _<ImageRenderer>().DrawImage(m_ridsTiles->at(x).at(y), groundImage, dest);

                if (mapX == player.GetX() && mapY == player.GetY())
                {
                    _<ImageRenderer>().DrawImage(m_ridPlayer, "Player", dest);
                }
            }
        }
    }
}