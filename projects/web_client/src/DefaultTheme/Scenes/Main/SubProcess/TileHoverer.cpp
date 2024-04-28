#include "TileHoverer.h"
#include "Core/Configuration/ClientProperties.h"
#include "Core/Engine/CoreGameObjects/Player.h"

namespace zw
{
    TileHoverer::TileHoverer(Engine &engine) : m_engine(engine)
    {
    }

    void TileHoverer::Update()
    {
        // auto numGridRows = _<ClientProperties>().NumGridRows();
        // auto numGridCols = CalculateNumGridCols(m_engine);

        // auto &player = _<Player>();
        // auto tileHeight = 1.0f / numGridRows;
        // auto tileWidth = ConvertHeightToWidth(m_engine, tileHeight);

        // auto mousePosition = GetMousePosition(m_engine);

        // auto hoveredCol = static_cast<int>(mousePosition.x / tileWidth);
        // auto hoveredRow = static_cast<int>(mousePosition.y / tileHeight);

        // m_hoveredCoordinate = { .x = player.GetX() - (numGridCols - 1) / 2 + hoveredCol,
        //                         .y = player.GetY() - (numGridRows - 1) / 2 + hoveredRow };
    }
}