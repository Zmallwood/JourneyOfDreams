//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams {
    class Test1 {
      public:
        Test1();
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