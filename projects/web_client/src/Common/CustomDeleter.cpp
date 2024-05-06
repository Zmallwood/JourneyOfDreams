// Copyright (c) 2024 Andreas Åkerberg.

#include "CustomDeleter.h"

// CustomDeleter class implementation.

namespace journey_of_dreams
{
  void CustomDeleter::operator()(SDL_Window *_window) {
    // Destroy the window.
    SDL_DestroyWindow(_window);
  }

  void CustomDeleter::operator()(SDL_Renderer *_renderer) {
    // Destroy the renderer.
    SDL_DestroyRenderer(_renderer);
  }

  void CustomDeleter::operator()(SDL_Surface *_surface) {
    // Destroy the surface.
    SDL_FreeSurface(_surface);
  }

  void CustomDeleter::operator()(SDL_Texture *_texture) {
    // Destroy the texture.
    SDL_DestroyTexture(_texture);
  }

  void CustomDeleter::operator()(TTF_Font *_font) {
    // Destroy the font.
    TTF_CloseFont(_font);
  }
} // namespace journey_of_dreams
