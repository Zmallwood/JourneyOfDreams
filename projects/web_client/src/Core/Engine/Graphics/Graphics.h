#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Setups and holds the graphics objects.
    /////////////////////////////////////////////////
    class Graphics
    {
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

        // /////////////////////////////////////////////////
        // /// Get the SDL window.
        // ///
        // /// \return SDL window.
        // /////////////////////////////////////////////////
        // std::shared_ptr<SDL_Window> Window();

        // /////////////////////////////////////////////////
        // /// Get the SDL renderer.
        // ///
        // /// \return SDL renderer.
        // /////////////////////////////////////////////////
        // std::shared_ptr<SDL_Renderer> Renderer();

        auto Window()
        {
            return window;
        }

      private:
        // std::shared_ptr<SDL_Window> m_window{};
        // std::shared_ptr<SDL_Renderer> m_renderer{};
        GLFWwindow *window;
    };
}
