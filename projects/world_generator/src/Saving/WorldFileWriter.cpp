// Copyright (c) 2024 Andreas Åkerberg.

#include "WorldFileWriter.h"
#include "../../shared/world_structure/src/Object.h"
#include "../../shared/world_structure/src/Tile.h"
#include "../../shared/world_structure/src/World.h"
#include "../../shared/world_structure/src/WorldArea.h"

// world_file_writer class implementation.

namespace journey_of_dreams
{
  void
  WorldFileWriter::WriteWorldToFile() {

    auto worldArea = _<World>().WorldArea();
    auto width = worldArea->GetSize().w;
    auto height = worldArea->GetSize().h;

    std::ofstream worldFile;
    worldFile.open(SDL_GetBasePath() + k_worldFileName);

    for (auto y = 0; y < height; y++) {
      for (auto x = 0; x < width; x++) {
        auto tile = worldArea->GetTile({.x = x, .y = y});
        auto groundHash = tile->Ground();

        worldFile << groundHash << std::endl;

        auto objectHash =
            tile->Object() != nullptr ? tile->Object()->Type() : 0;

        worldFile << objectHash << std::endl;
      }
    }

    worldFile.close();
  }
} // namespace journey_of_dreams