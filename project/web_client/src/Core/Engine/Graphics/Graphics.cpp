#include "Graphics.h"
#include "configuration/src/GameProperties.h"

EM_JS(int, canvas_get_width, (), { return window.innerWidth; });

EM_JS(int, canvas_get_height, (), { return window.innerHeight; });

namespace zw
{
    Graphics::Graphics() 
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        auto canvasSize = _<GameProperties>().CanvasSize();

        m_window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow("Journey of Dreams", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             canvas_get_width(), canvas_get_height(), SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN),
            SDLDeleter());

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetSwapInterval(0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        auto glContext = SDL_GL_CreateContext(m_window.get());

        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE),
            SDLDeleter());

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        auto defaultClearColor = _<GameProperties>().DefaultClearColor();

        glClearColor(defaultClearColor.r, defaultClearColor.g, defaultClearColor.b, defaultClearColor.a);
    }

    void Graphics::ClearCanvas()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Graphics::PresentCanvas()
    {

        SDL_GL_SwapWindow(m_window.get());
    }
}