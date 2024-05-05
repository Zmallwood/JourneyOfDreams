//  Copyright (C) 2024 Andreas Åkerberg

#include "GenerateNewWorld.h"
#include "../../shared/world_structure/src/World.h"
#include "SubProcess/GenerateGrass.h"
#include "SubProcess/GenerateObjects.h"
#include "SubProcess/GenerateWater.h"

namespace JourneyOfDreams {
    void GenerateNewWorld() {
        srand(time(0));
        GenerateGrass();
        GenerateWater();
        GenerateObjects();
    }
}