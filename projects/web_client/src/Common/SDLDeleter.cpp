/* Copyright (c) 2024 Andreas Åkerberg. */

#include "SDLDeleter.h"

/* SDLDeleter class implementation. */

namespace JourneyOfDreams
{
  void SDLDeleter::operator()(SDL_Window *window) {
    /* Destroy the window. */
    SDL_DestroyWindow(window);
  }

  void SDLDeleter::operator()(SDL_Renderer *renderer) {
    /* Destroy the renderer. */
    SDL_DestroyRenderer(renderer);
  }

  void SDLDeleter::operator()(SDL_Surface *surface) {
    /* Destroy the surface. */
    SDL_FreeSurface(surface);
  }

  void SDLDeleter::operator()(SDL_Texture *texture) {
    /* Destroy the texture. */
    SDL_DestroyTexture(texture);
  }

  void SDLDeleter::operator()(TTF_Font *font) {
    /* Destroy the font. */
    TTF_CloseFont(font);
  }
}
