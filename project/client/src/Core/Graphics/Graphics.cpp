#include "Graphics.h"

namespace zw
{
    Graphics::Graphics()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        m_window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED,
                                                                SDL_WINDOWPOS_CENTERED, 1000, 800,
                                                                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN),
                                               SDLDeleter());

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
        SDL_GL_SetSwapInterval(0);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        auto glc = SDL_GL_CreateContext(m_window.get());

        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE),
            SDLDeleter());
    }
}