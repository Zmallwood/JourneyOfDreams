// Copyright (c) 2024 Andreas Åkerberg.

#include "custom_deleter.h"

// custom_deleter class implementation.

namespace journey_of_dreams
{
  void
  custom_deleter::operator()(SDL_Window *win) {
    // destroy the window
    SDL_DestroyWindow(win);
  }

  void
  custom_deleter::operator()(SDL_Renderer *rend) {
    // destroy the renderer
    SDL_DestroyRenderer(rend);
  }

  void
  custom_deleter::operator()(SDL_Surface *surf) {
    // destroy the surface
    SDL_FreeSurface(surf);
  }

  void
  custom_deleter::operator()(SDL_Texture *tex) {
    // destroy the texture
    SDL_DestroyTexture(tex);
  }

  void
  custom_deleter::operator()(TTF_Font *font) {
    // destroy the font
    TTF_CloseFont(font);
  }
} // namespace journey_of_dreams
