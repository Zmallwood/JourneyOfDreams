//  Copyright (C) 2024 Andreas Åkerberg

#include "EnsureGoodPlayerPosition.h"
#include "Core/Engine/CoreGameObjects/Player.h"
#include "world_structure/src/Tile.h"
#include "world_structure/src/World.h"
#include "world_structure/src/WorldArea.h"

namespace JourneyOfDreams
{
    static bool CoordinateIsGoodAsPlayerPosition(Point coordinate)
    {
        auto worldArea = _<World>().WorldArea();
        auto tile = worldArea->GetTile(coordinate);

        if (!tile->IsWalkable()) {
            return false;
        }

        return true;
    }

    void EnsureGoodPlayerPosition()
    {
        auto worldArea = _<World>().WorldArea();
        Point coordinate;
        do
        {
            coordinate = worldArea->GetRandomCoordinate();
        } while (CoordinateIsGoodAsPlayerPosition(coordinate) == false);

        auto &player = _<Player>();
        player.SetPosition(coordinate);
    }
}