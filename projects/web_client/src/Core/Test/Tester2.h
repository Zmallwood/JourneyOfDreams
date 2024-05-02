#pragma once

namespace JourneyOfDreams
{
    class Tester2
    {
      public:
        Tester2();
        void Render();
        void Stop();

      private:
        bool m_active{ true };
        SDL_Window *m_window{ nullptr };
        SDL_Renderer *m_renderer{ nullptr };
        GLuint m_vao;
        GLuint m_vbo;
        GLuint m_ebo;
        unsigned int m_shaderProgram;
    };
}