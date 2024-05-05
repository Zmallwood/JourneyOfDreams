// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace JourneyOfDreams {
    /////////////////////////////////////////////////
    /// Setups and holds the graphics objects.
    /////////////////////////////////////////////////
    class Graphics {
      public:
        /////////////////////////////////////////////////
        /// Setup SDL window, GL context and SDL renderer.
        /////////////////////////////////////////////////
        Graphics();

        /////////////////////////////////////////////////
        /// Clear canvas at the beginning of each frame.
        /////////////////////////////////////////////////
        void ClearCanvas();

        /////////////////////////////////////////////////
        /// Present canvas at the end of each frame.
        /////////////////////////////////////////////////
        void PresentCanvas();

        GLFWwindow * Window();

      private:
        GLFWwindow *window;
    };
}
