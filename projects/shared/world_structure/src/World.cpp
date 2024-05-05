// Copyright (c) 2024 Andreas Åkerberg.

#include "World.h"
#include "WorldArea.h"

namespace journey_of_dreams
{
  World::World()
      : m_worldArea(std::make_shared<journey_of_dreams::WorldArea>()) {
  }
} // namespace journey_of_dreams