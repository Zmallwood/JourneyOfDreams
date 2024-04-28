#include "TileGridCalculations.h"
#include "Core/Configuration/ClientProperties.h"
#include "Core/Engine/Engine.h"

namespace zw
{
    int CalculateNumGridCols(Engine& engine)
    {
        return -1;
        // auto numGridRows = _<ClientProperties>().NumGridRows();

        // auto tileHeight = 1.0f / numGridRows;
        // auto tileWidth = ConvertHeightToWidth(engine, tileHeight);

        // auto numGridCols = static_cast<int>(std::ceil(1.0f / tileWidth));

        // numGridCols = numGridCols % 2 == 0 ? numGridCols + 1 : numGridCols;

        // return numGridCols;
    }
}