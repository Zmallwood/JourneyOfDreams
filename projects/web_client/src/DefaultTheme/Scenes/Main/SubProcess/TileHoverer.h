// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams
{
  class TileHoverer {
   public:
    void Update();
    auto
    HoveredCoordinate() const {
      return m_hoveredCoordinate;
    }

   private:
    Point m_hoveredCoordinate{-1, -1};
  };
} // namespace journey_of_dreams