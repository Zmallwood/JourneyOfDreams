#include "SDLDeleter.h"

namespace zw
{
    void SDLDeleter::operator()(SDL_Window *window)
    {
        SDL_DestroyWindow(window);
    }

    void SDLDeleter::operator()(SDL_Renderer *renderer)
    {
        SDL_DestroyRenderer(renderer);
    }

    void SDLDeleter::operator()(SDL_Surface *surface)
    {
        SDL_FreeSurface(surface);
    }

    void SDLDeleter::operator()(SDL_Texture *texture)
    {
        SDL_DestroyTexture(texture);
    }

    void SDLDeleter::operator()(TTF_Font *font)
    {
        TTF_CloseFont(font);
    }
}