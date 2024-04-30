#include "Graphics.h"
#include "Core/Configuration/ClientProperties.h"

EM_JS(int, canvas_get_width, (), { return window.innerWidth; });
EM_JS(int, canvas_get_height, (), { return window.innerHeight; });

namespace JourneyOfDreams
{
    Graphics::Graphics()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        /*
        ** Create SDL window, which in emscripten becomes a canvas in the html page. */
        m_window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow("Journey of Dreams", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                             canvas_get_width(), canvas_get_height(), SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN),
            SDLDeleter());

        /*
        ** Set OpenGL attributes. */
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetSwapInterval(0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        /*
        ** Create OpenGL context. */
        auto glContext = SDL_GL_CreateContext(m_window.get());

        /*
        ** Create SDL renderer. */
        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE),
            SDLDeleter());

        /*
        ** Enable alpha blending. */
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        /*
        ** Get default clear color from configuration and apply it. */
        auto defaultClearColor = _<ClientProperties>().DefaultClearColor();
        glClearColor(defaultClearColor.r, defaultClearColor.g, defaultClearColor.b, defaultClearColor.a);
    }

    void Graphics::ClearCanvas()
    {
        /*
        ** Clear canvas at the beginning of each frame. */
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Graphics::PresentCanvas()
    {
        /*
        ** Present canvas at the end of each frame. */
        SDL_GL_SwapWindow(m_window.get());
    }

    std::shared_ptr<SDL_Window> Graphics::Window()
    {
        /*
        ** Getter */
        return m_window;
    }

    std::shared_ptr<SDL_Renderer> Graphics::Renderer()
    {
        /*
        ** Getter */
        return m_renderer;
    }
}