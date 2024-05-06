/* Copyright (c) 2024 Andreas Åkerberg. */

#include "TileHoverer.h"
#include "Core/Configuration/ClientProperties.h"
#include "Core/Engine/CoreGameObjects/Player.h"

// tile_hoverer class implementation.

namespace JourneyOfDreams
{
  void TileHoverer::Update() {
    auto numGridRows = _<ClientProperties>().NumGridRows();
    auto numGridCols = CalculateNumGridCols();

    auto &player = _<Player>();
    auto tileHeight = 1.0f / numGridRows;
    auto tileWidth = ConvertHeightToWidth(tileHeight);

    auto mousePosition = GetMousePosition();

    auto hoveredCol = static_cast<int>(mousePosition.x / tileWidth);
    auto hoveredRow = static_cast<int>(mousePosition.y / tileHeight);

    m_hoveredCoordinate = {
        .x = player.GetX() - (numGridCols - 1) / 2 + hoveredCol,
        .y = player.GetY() - (numGridRows - 1) / 2 + hoveredRow};
  }
}