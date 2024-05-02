#include "Tester1.h"

EM_JS(int, canvas_get_width, (), { return window.innerWidth; });
EM_JS(int, canvas_get_height, (), { return window.innerHeight; });

namespace JourneyOfDreams
{
    Tester1::Tester1()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        /*
        ** Create SDL window, which in emscripten becomes a canvas in the html page. */
        m_window
            = SDL_CreateWindow("Journey of Dreams", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               canvas_get_width(), canvas_get_height(), SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        /*
        ** Set OpenGL attributes. */
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetSwapInterval(0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        /*
        ** Create OpenGL context. */
        auto glContext = SDL_GL_CreateContext(m_window);
        /*
        ** Create SDL renderer. */
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
        /*
        ** Enable alpha blending. */
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    }

    void Tester1::Render()
    {
        if (!m_active)
        {
            return;
        }
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(m_window);
    }

    void Tester1::Stop()
    {
        m_active = false;
        SDL_DestroyRenderer(m_renderer), SDL_DestroyWindow(m_window);
    }
}