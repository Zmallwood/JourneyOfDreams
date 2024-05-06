/* Copyright (c) 2024 Andreas Åkerberg. */

#include "TileGridCalculations.h"
#include "Core/Configuration/ClientProperties.h"

/* TileGridCalculations implementation. */

namespace JourneyOfDreams
{
  int CalculateNumGridCols() {
    /* 1) Get number of grid rows from configuration.
     * 2) Divide the canvas height (1.0f) with number of rows to get
     *    tile height.
     * 3) Convert tile height to tile width.
     * 4) Divide canvas width (1.0f) with tile width to get number of columns.
     * 5) Ensure that number of columns is always an odd number.
     * 6) Return calculated results. */
    auto numGridRows{_<ClientProperties>().NumGridRows()};
    auto tileHeight{1.0f / numGridRows};
    auto tileWidth{ConvertHeightToWidth(tileHeight)};
    auto numGridCols{static_cast<int>(std::ceil(1.0f / tileWidth))};
    numGridCols = numGridCols % 2 == 0 ? numGridCols + 1 : numGridCols;
    return numGridCols;
  }
}