/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* TileHoverer class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Tracks the hovered tile coordinate.
  /////////////////////////////////////////////////
  class TileHoverer {
   public:
    /////////////////////////////////////////////////
    /// Update the hovered tile coordinate.
    /////////////////////////////////////////////////
    void Update();

    /////////////////////////////////////////////////
    /// Get the hovered tile coordinate.
    ///
    /// @return The hovered tile coordinate.
    /////////////////////////////////////////////////
    Point HoveredCoordinate() const;

   private:
    Point m_hoveredCoordinate{-1, -1};
  };
}