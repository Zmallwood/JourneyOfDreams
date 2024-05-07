/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Tile.h"

/* Tile class implementation. */

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

  int Tile::Ground() {
    return m_ground;
  }

  float Tile::Elevation() {
    return m_elevation;
  }

  std::shared_ptr<JourneyOfDreams::Object> Tile::Object() {
    return m_object;
  }

  void Tile::SetObject(const std::shared_ptr<JourneyOfDreams::Object> object) {
    m_object = object;
  }
}