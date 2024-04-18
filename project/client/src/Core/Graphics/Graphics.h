#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace zw
{
    class Graphics
    {
      public:
        Graphics();
        auto Window()
        {
            return m_window;
        }
        auto Renderer()
        {
            return m_renderer;
        }

      private:
        std::shared_ptr<SDL_Window> m_window{};
        std::shared_ptr<SDL_Renderer> m_renderer{};
    };
}