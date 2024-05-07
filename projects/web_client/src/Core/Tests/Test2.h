/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* Test2 class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Performs the second test when loading the game.
  /// It renders a simple image to the screen with its
  /// own simple shaders and only using the ImageBank
  /// and no other components from the engine.
  /////////////////////////////////////////////////
  class Test2 {
   public:
    /////////////////////////////////////////////////
    /// Sets up the test.
    /////////////////////////////////////////////////
    Test2();

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
    SDL_Window *m_window{nullptr};
    SDL_Renderer *m_renderer{nullptr};
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_ebo;
    unsigned int m_shaderProgram;
  };
}