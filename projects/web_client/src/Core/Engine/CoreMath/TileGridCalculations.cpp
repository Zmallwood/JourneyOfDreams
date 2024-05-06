// Copyright (c) 2024 Andreas Åkerberg.

#include "TileGridCalculations.h"
#include "Core/Configuration/ClientProperties.h"

// TileGridCalculations implementation.

namespace JourneyOfDreams
{
  int
  CalculateNumGridCols() {
    // get number of grid rows from configuration
    auto numGridRows = _<ClientProperties>().NumGridRows();
    // divide the canvas height (1.0f) with number of rows to get tile height
    auto tileHeight = 1.0f / numGridRows;
    // convert tile height to tile width
    auto tileWidth = ConvertHeightToWidth(tileHeight);
    // divide tile width (1.0f) with tile width to get number of columns
    auto numGridCols = static_cast<int>(std::ceil(1.0f / tileWidth));
    // ensure that number of columns is always an odd number
    numGridCols = numGridCols % 2 == 0 ? numGridCols + 1 : numGridCols;
    // results calculated
    return numGridCols;
  }
} // namespace JourneyOfDreams