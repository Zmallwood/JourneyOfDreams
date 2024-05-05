// Copyright (c) 2024 Andreas Åkerberg.

#include "World.h"
#include "WorldArea.h"

namespace JourneyOfDreams {
    World::World() : m_worldArea(std::make_shared<JourneyOfDreams::WorldArea>()) {
    }
}