/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* FPSCounter class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Counts and displays the frames per second.
  /////////////////////////////////////////////////
  class FPSCounter {
   public:
    /////////////////////////////////////////////////
    /// Set up GUILabel to display FPS.
    /////////////////////////////////////////////////
    FPSCounter();

    /////////////////////////////////////////////////
    /// Calculate the frames per second.
    /////////////////////////////////////////////////
    void Update();

    /////////////////////////////////////////////////
    /// Update the GUILabel with the FPS.
    /////////////////////////////////////////////////
    void Render();

   private:
    int m_fps{0};
    int m_framesCount{0};
    int m_ticksLastUpdate{0};
  };
}