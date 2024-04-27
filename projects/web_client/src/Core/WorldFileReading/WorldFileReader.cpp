#include "WorldFileReader.h"
#include "world_structure/src/World.h"
#include "world_structure/src/WorldArea.h"
#include "world_structure/src/Tile.h"

namespace zw
{
    void WorldFileReader::ReadWorldFile()
    {
        auto worldArea = _<World>().WorldArea();
        auto width = worldArea->GetSize().w;
        auto height = worldArea->GetSize().h;

        std::ifstream worldFile;
        worldFile.open(SDL_GetBasePath() + k_worldFileName);

        std::string line;

        for (auto y = 0; y < height; y++)
        {
            for (auto x = 0; x < width; x++)
            {
                std::getline(worldFile, line);

                auto tile = worldArea->GetTile({ .x = x, .y = y });
                auto groundHash = std::stoi(line);
                tile->SetGround(groundHash);
            }
        }

        worldFile.close();
    }
}