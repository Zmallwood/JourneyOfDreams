#include "TileGridCalculations.h"
#include "Core/Configuration/ClientProperties.h"

namespace zw
{
    int CalculateNumGridCols()
    {
        auto numGridRows = _<ClientProperties>().NumGridRows();

        auto tileHeight = 1.0f / numGridRows;
        auto tileWidth = ConvertHeightToWidth(tileHeight);

        auto numGridCols = static_cast<int>(std::ceil(1.0f / tileWidth));

        numGridCols = numGridCols % 2 == 0 ? numGridCols + 1 : numGridCols;

        return numGridCols;
    }
}