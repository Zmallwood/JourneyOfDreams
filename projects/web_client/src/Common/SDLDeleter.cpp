#include "SDLDeleter.h"

namespace JourneyOfDreams
{
    void SDLDeleter::operator()(SDL_Window *window)
    {
        /*
         * Free allocated SDL window object. */
        SDL_DestroyWindow(window);
    }

    void SDLDeleter::operator()(SDL_Renderer *renderer)
    {
        /*
         * Free allocated SDL renderer object. */
        SDL_DestroyRenderer(renderer);
    }

    void SDLDeleter::operator()(SDL_Surface *surface)
    {
        /*
         * Free allocated SDL surface object. */
        SDL_FreeSurface(surface);
    }

    void SDLDeleter::operator()(SDL_Texture *texture)
    {
        /*
         * Free allocated SDL texture object. */
        SDL_DestroyTexture(texture);
    }

    void SDLDeleter::operator()(TTF_Font *font)
    {
        /*
         * Free allocated SDL_ttf font object. */
        TTF_CloseFont(font);
    }
}
