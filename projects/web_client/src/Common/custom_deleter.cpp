// Copyright (c) 2024 Andreas Åkerberg.

#include "custom_deleter.h"

// custom_deleter class implementation.

namespace journey_of_dreams
{
  void custom_deleter::operator()(SDL_Window *_window) {
    // destroy the window
    SDL_DestroyWindow(_window);
  }

  void custom_deleter::operator()(SDL_Renderer *_renderer) {
    // destroy the renderer
    SDL_DestroyRenderer(_renderer);
  }

  void custom_deleter::operator()(SDL_Surface *_surface) {
    // destroy the surface
    SDL_FreeSurface(_surface);
  }

  void custom_deleter::operator()(SDL_Texture *_texture) {
    // destroy the texture
    SDL_DestroyTexture(_texture);
  }

  void custom_deleter::operator()(TTF_Font *_font) {
    // destroy the font
    TTF_CloseFont(_font);
  }
} // namespace journey_of_dreams
