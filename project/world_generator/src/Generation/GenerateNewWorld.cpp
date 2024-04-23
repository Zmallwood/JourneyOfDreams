#include "GenerateNewWorld.h"
#include "../../shared/world_structure/src/World.h"
#include "SubProcess/GenerateGrass.h"

namespace zw
{
    std::shared_ptr<WorldArea> GenerateNewWorld()
    {
        auto worldArea = _<World>().WorldArea();
        GenerateGrass(worldArea);

        return worldArea;
    }
}