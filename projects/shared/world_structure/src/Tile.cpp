/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Tile.h"

// tile class implementation.

namespace JourneyOfDreams
{
  void Tile::SetGround(const std::string &groundName) {
    m_ground = Hash(groundName);
  }

  void Tile::SetGround(int groundHash) {
    m_ground = groundHash;
  }

  bool Tile::IsWalkable() {
    return m_ground != Hash("GroundWater");
  }
}