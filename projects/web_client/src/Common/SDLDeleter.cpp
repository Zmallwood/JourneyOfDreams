#include "SDLDeleter.h"

namespace JourneyOfDreams
{
    void SDLDeleter::operator()(SDL_Window *window)
    {
        SDL_DestroyWindow(window); // Free allocated SDL window object.
    }

    void SDLDeleter::operator()(SDL_Renderer *renderer)
    {
        SDL_DestroyRenderer(renderer); // Free allocated SDL renderer object.
    }

    void SDLDeleter::operator()(SDL_Surface *surface)
    {
        SDL_FreeSurface(surface); // Free allocated SDL surface object.
    }

    void SDLDeleter::operator()(SDL_Texture *texture)
    {
        SDL_DestroyTexture(texture); // Free allocated SDL texture object.
    }

    void SDLDeleter::operator()(TTF_Font *font)
    {
        TTF_CloseFont(font); // Free allocated SDL_ttf font object.
    }
}
