/* Copyright (c) 2024 Andreas Åkerberg. */

#include "World.h"
#include "WorldArea.h"

/* World class implementation. */

namespace JourneyOfDreams
{
  World::World()
      : m_worldArea(std::make_shared<JourneyOfDreams::WorldArea>()) {
  }

  std::shared_ptr<JourneyOfDreams::WorldArea> World::WorldArea() {
    return m_worldArea;
  }
}