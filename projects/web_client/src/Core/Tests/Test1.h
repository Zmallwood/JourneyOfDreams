/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* Test1 class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Performs the first test when loading the game.
  /// It renders a simple colored shape to the screen with
  /// its own simple shaders and without using any loaded
  /// file textures or other parts of the engine.
  /////////////////////////////////////////////////
  class Test1 {
   public:
    /////////////////////////////////////////////////
    /// Sets up the test.
    /////////////////////////////////////////////////
    Test1();

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