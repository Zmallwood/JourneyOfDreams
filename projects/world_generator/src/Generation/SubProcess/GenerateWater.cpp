#include "GenerateWater.h"
#include "../../shared/world_structure/src/Tile.h"
#include "../../shared/world_structure/src/World.h"
#include "../../shared/world_structure/src/WorldArea.h"

namespace zw
{
    void GenerateWater()
    {
        // auto worldArea = _<World>().WorldArea();
        // auto width = worldArea->GetSize().w;
        // auto height = worldArea->GetSize().h;

        // auto numLakes = 50;

        // for (auto i = 0; i < numLakes; i++)
        // {
        //     auto xCenter = rand() % width;
        //     auto yCenter = rand() % height;
        //     auto r = rand() % 3 + 7;

        //     for (auto y = yCenter - r; y <= yCenter + r; y++)
        //     {
        //         for (auto x = xCenter - r; x <= xCenter + r; x++)
        //         {
        //             if (x < 0 || y < 0 || x >= width || y >= height)
        //             {
        //                 continue;
        //             }

        //             auto dx = x - xCenter;
        //             auto dy = y - yCenter;

        //             if (dx * dx + dy * dy <= r * r)
        //             {
        //                 auto tile = worldArea->GetTile({ .x = x, .y = y });
        //                 tile->SetGround("GroundWater");
        //             }
        //         }
        //     }
        // }
    }
}