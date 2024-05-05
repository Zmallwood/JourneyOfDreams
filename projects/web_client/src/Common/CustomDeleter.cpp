// Copyright (c) 2024 Andreas Åkerberg.

#include "CustomDeleter.h"

// CustomDeleter class implementation.

namespace journey_of_dreams
{
  void CustomDeleter::operator()(SDL_Window *_window) {
    // destroy the window
    SDL_DestroyWindow(_window);
  }

  void CustomDeleter::operator()(SDL_Renderer *_renderer) {
    // destroy the renderer
    SDL_DestroyRenderer(_renderer);
  }

  void CustomDeleter::operator()(SDL_Surface *_surface) {
    // destroy the surface
    SDL_FreeSurface(_surface);
  }

  void CustomDeleter::operator()(SDL_Texture *_texture) {
    // destroy the texture
    SDL_DestroyTexture(_texture);
  }

  void CustomDeleter::operator()(TTF_Font *_font) {
    // destroy the font
    TTF_CloseFont(_font);
  }
} // namespace journey_of_dreams
