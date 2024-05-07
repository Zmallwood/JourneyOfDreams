/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* WorldView class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Renders the world to the canvas.
  /////////////////////////////////////////////////
  class WorldView {
   public:
    /////////////////////////////////////////////////
    /// Allocate graphics resources.
    /////////////////////////////////////////////////
    WorldView();

    /////////////////////////////////////////////////
    /// Does nothing.
    /////////////////////////////////////////////////
    void Update();

    /////////////////////////////////////////////////
    /// Draw the world ground, objects and player to the canvas.
    /////////////////////////////////////////////////
    void Render();

   private:
    std::shared_ptr<std::vector<std::vector<RID>>> m_ridsTiles;
    std::shared_ptr<std::vector<std::vector<RID>>> m_ridsObjects;
    RID m_ridPlayer;
    RID m_ridHoveredTile;
  };
}