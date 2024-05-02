//  Copyright (C) 2024 Andreas Åkerberg

#include "GenerateObjects.h"
#include "../../shared/world_structure/src/Object.h"
#include "../../shared/world_structure/src/Tile.h"
#include "../../shared/world_structure/src/World.h"
#include "../../shared/world_structure/src/WorldArea.h"

namespace JourneyOfDreams
{
    void GenerateObjects()
    {
        auto worldArea = _<World>().WorldArea();

        auto numTree1s = 400;

        for (auto i = 0; i < numTree1s; i++)
        {
            auto tile = worldArea->GetRandomTile();

            if (tile->Ground() != Hash("GroundWater"))
            {
                tile->SetObject(std::make_shared<Object>("ObjectTree1"));
            }
        }

        auto numTree2s = 400;

        for (auto i = 0; i < numTree2s; i++)
        {
            auto tile = worldArea->GetRandomTile();

            if (tile->Ground() != Hash("GroundWater"))
            {
                tile->SetObject(std::make_shared<Object>("ObjectTree2"));
            }
        }

        auto numBush1s = 400;

        for (auto i = 0; i < numBush1s; i++)
        {
            auto tile = worldArea->GetRandomTile();

            if (tile->Ground() != Hash("GroundWater"))
            {
                tile->SetObject(std::make_shared<Object>("ObjectBush1"));
            }
        }
    }
}