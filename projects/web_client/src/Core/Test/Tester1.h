#pragma once

namespace JourneyOfDreams
{
    class Tester1
    {
      public:
        Tester1();
        void Render();
        void Stop();

        private:
        bool m_active { true };
        SDL_Window* m_window { nullptr };
        SDL_Renderer* m_renderer { nullptr};
    };
}