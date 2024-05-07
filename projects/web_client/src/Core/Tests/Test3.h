/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* Test3 class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Performs the third test when loading the game.
  /// It renders a simple image to the screen using the
  /// ImageRenderer, and thereby also the ImageBank,
  /// RendererBase and ShaderProram components of the Engine.
  /////////////////////////////////////////////////
  class Test3 {
   public:
    /////////////////////////////////////////////////
    /// Sets up the test.
    /////////////////////////////////////////////////
    Test3();

    /////////////////////////////////////////////////
    /// Renders the test in the Emscripten game loop.
    /////////////////////////////////////////////////
    void Render();

    /////////////////////////////////////////////////
    /// Frees resources used by the test and sets it as
    /// inactive to stop it from stealing performance
    /// from the actual game.
    /////////////////////////////////////////////////
    void Stop();

   private:
    bool m_active{true};
    RID m_ridImage{0};
  };
}