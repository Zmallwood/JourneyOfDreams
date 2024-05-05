// Copyright (c) 2024 Andreas Åkerberg.

#include "WorldFileReader.h"
#include "world_structure/src/Object.h"
#include "world_structure/src/Tile.h"
#include "world_structure/src/World.h"
#include "world_structure/src/WorldArea.h"

// world_file_reader class implementation.

namespace journey_of_dreams
{
  void
  WorldFileReader::ReadWorldFile() {
    auto worldArea = _<World>().WorldArea();
    auto width = worldArea->GetSize().w;
    auto height = worldArea->GetSize().h;

    std::ifstream worldFile;
    worldFile.open(SDL_GetBasePath() + k_worldFileName);

    std::string line;

    for (auto y = 0; y < height; y++) {
      for (auto x = 0; x < width; x++) {
        auto tile = worldArea->GetTile({.x = x, .y = y});

        std::getline(worldFile, line);

        auto groundHash = std::stoi(line);
        tile->SetGround(groundHash);

        std::getline(worldFile, line);

        auto objectHash = std::stoi(line);
        if (objectHash != 0) {
          tile->SetObject(std::make_shared<Object>(objectHash));
        }
      }
    }

    worldFile.close();
  }
} // namespace journey_of_dreams