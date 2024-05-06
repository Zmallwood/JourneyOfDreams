// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// tile class declaration.

namespace JourneyOfDreams
{
  class Object;

  class Tile {
   public:
    void SetGround(const std::string &groundName);
    void SetGround(int groundHash);
    bool IsWalkable();
    auto

    Ground() {
      return m_ground;
    }

    auto
    Elevation() {
      return m_elevation;
    }

    auto
    Object() {
      return m_object;
    }

    void
    SetObject(const std::shared_ptr<JourneyOfDreams::Object> object) {
      m_object = object;
    }

   private:
    int m_ground{0};
    float m_elevation{0.0f};
    std::shared_ptr<JourneyOfDreams::Object> m_object{};
  };
} // namespace JourneyOfDreams