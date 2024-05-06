/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* TileHoverer class declaration. */

namespace JourneyOfDreams
{
  class TileHoverer {
   public:
    void Update();
    auto HoveredCoordinate() const {
      return m_hoveredCoordinate;
    }

   private:
    Point m_hoveredCoordinate{-1, -1};
  };
}