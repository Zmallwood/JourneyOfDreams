/* Copyright (c) 2024 Andreas Åkerberg. */

#include "CustomDeleter.h"

/* CustomDeleter class implementation. */

namespace JourneyOfDreams
{
  void CustomDeleter::operator()(SDL_Window *window) {
    /* Destroy the window. */
    SDL_DestroyWindow(window);
  }

  void CustomDeleter::operator()(SDL_Renderer *renderer) {
    /* Destroy the renderer. */
    SDL_DestroyRenderer(renderer);
  }

  void CustomDeleter::operator()(SDL_Surface *surface) {
    /* Destroy the surface. */
    SDL_FreeSurface(surface);
  }

  void CustomDeleter::operator()(SDL_Texture *texture) {
    /* Destroy the texture. */
    SDL_DestroyTexture(texture);
  }

  void CustomDeleter::operator()(TTF_Font *font) {
    /* Destroy the font. */
    TTF_CloseFont(font);
  }
}
