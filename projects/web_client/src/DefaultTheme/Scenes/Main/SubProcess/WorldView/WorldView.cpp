#include "WorldView.h"
#include "Core/Configuration/ClientProperties.h"
#include "Core/Engine/CoreGameObjects/Player.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "world_structure/src/Object.h"
#include "world_structure/src/Tile.h"
#include "world_structure/src/World.h"
#include "world_structure/src/WorldArea.h"

namespace zw
{
    WorldView::WorldView()
        : m_ridsTiles(std::make_shared<std::vector<std::vector<RID>>>()),
          m_ridsObjects(std::make_shared<std::vector<std::vector<RID>>>())
    {
        auto numGridRows = _<ClientProperties>().NumGridRows();
        auto numGridCols = CalculateNumGridCols();

        for (auto x = 0; x < numGridCols; x++)
        {
            m_ridsTiles->push_back(std::vector<RID>());
            m_ridsObjects->push_back(std::vector<RID>());
            for (auto y = 0; y < numGridRows; y++)
            {
                m_ridsTiles->at(x).push_back(_<ImageRenderer>().NewImage());
                m_ridsObjects->at(x).push_back(_<ImageRenderer>().NewImage());
            }
        }

        m_ridPlayer = _<ImageRenderer>().NewImage();
    }

    void WorldView::Update()
    {
    }

    void WorldView::Render()
    {
        auto numGridRows = _<ClientProperties>().NumGridRows();
        auto numGridCols = CalculateNumGridCols();

        auto worldArea = _<World>().WorldArea();
        auto &player = _<Player>();
        auto tileHeight = 1.0f / numGridRows;
        auto tileWidth = ConvertHeightToWidth(tileHeight);
        for (auto y = 0; y < numGridRows; y++)
        {
            for (auto x = 0; x < numGridCols; x++)
            {
                auto mapX = player.GetX() - (numGridCols - 1) / 2 + x;
                auto mapY = player.GetY() - (numGridRows - 1) / 2 + y;

                if (mapX < 0 || mapY < 0 || mapX >= worldArea->GetSize().w || mapY >= worldArea->GetSize().h)
                {
                    continue;
                }

                auto tile = worldArea->GetTile({ .x = mapX, .y = mapY });

                auto tileX = 0.5f - (numGridCols - 1) / 2 * tileWidth + x * tileWidth;
                auto tileY = y * tileHeight;

                auto dest = RectF{ tileX, tileY, tileWidth, tileHeight };
                std::string groundImage;

                if (tile->Ground() == Hash("GroundGrass"))
                {
                    groundImage = "GroundGrass";
                }
                else if (tile->Ground() == Hash("GroundWater"))
                {

                    auto animIndex = (Ticks() % 1200) / 400;
                    groundImage = "GroundWater_" + std::to_string(animIndex);
                }

                _<ImageRenderer>().DrawImage(m_ridsTiles->at(x).at(y), groundImage, dest);

                if (tile->Object() != nullptr)
                {
                    _<ImageRenderer>().DrawImage(m_ridsObjects->at(x).at(y), tile->Object()->Type(), dest);
                }

                if (mapX == player.GetX() && mapY == player.GetY())
                {
                    _<ImageRenderer>().DrawImage(m_ridPlayer, "Player", dest);
                }
            }
        }
    }
}