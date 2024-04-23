#include "GenerateGrass.h"
#include "../../shared/world_structure/src/WorldArea.h"
#include "../../shared/world_structure/src/Tile.h"

namespace zw
{
    void GenerateGrass(std::shared_ptr<WorldArea> worldArea)
    {
        auto width = worldArea->GetSize().w;
        auto height = worldArea->GetSize().h;

        for (auto y = 0; y < height; y++)
        {
            for (auto x = 0; x < width; x++)
            {
                worldArea->GetTile({ .x = x, .y = y })->SetGround("GroundGrass");
            }
        }
    }
}