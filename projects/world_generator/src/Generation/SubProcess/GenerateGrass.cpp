/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GenerateGrass.h"
#include "../../shared/world_structure/src/Tile.h"
#include "../../shared/world_structure/src/World.h"
#include "../../shared/world_structure/src/WorldArea.h"

/* GenerateGrass function implementation. */

namespace JourneyOfDreams
{
  void GenerateGrass() {
    auto worldArea = _<World>().WorldArea();
    auto width = worldArea->GetSize().w;
    auto height = worldArea->GetSize().h;

    for (auto y = 0; y < height; y++) {
      for (auto x = 0; x < width; x++) {
        auto tile = worldArea->GetTile({.x = x, .y = y});
        tile->SetGround("GroundGrass");
      }
    }
  }
}