/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

/* CustomDeleter class declaration. */

namespace journey_of_dreams
{
  class CustomDeleter {
   public:
    /////////////////////////////////////////////////
    /// Destroy SDL window object.
    ///
    /// @param _window SDL window object.
    /////////////////////////////////////////////////
    void operator()(SDL_Window *_window);

    /////////////////////////////////////////////////
    /// estroy SDL renderer object.
    ///
    /// @param _renderer SDL renderer object.
    /////////////////////////////////////////////////
    void operator()(SDL_Renderer *_renderer);

    /////////////////////////////////////////////////
    /// Destroy SDL surface object.
    ///
    /// @param _surface SDL surface object.
    /////////////////////////////////////////////////
    void operator()(SDL_Surface *_surface);

    /////////////////////////////////////////////////
    /// Destroy SDL texture object.
    ///
    /// @param _texture SDL texture object.
    /////////////////////////////////////////////////
    void operator()(SDL_Texture *_texture);

    /////////////////////////////////////////////////
    /// Destroy SDL font object.
    ///
    /// @param _font SDL font object.
    /////////////////////////////////////////////////
    void operator()(TTF_Font *_font);
  };
}
