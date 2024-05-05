// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

// custom_deleter class declaration.

namespace journey_of_dreams
{
  class custom_deleter {
   public:
    /////////////////////////////////////////////////
    /// Destroy SDL window object.
    ///
    /// \param win SDL window object.
    /////////////////////////////////////////////////
    void operator()(SDL_Window *win);

    /////////////////////////////////////////////////
    /// estroy SDL renderer object.
    ///
    /// \param rend SDL renderer object.
    /////////////////////////////////////////////////
    void operator()(SDL_Renderer *rend);

    /////////////////////////////////////////////////
    /// Destroy SDL surface object.
    ///
    /// \param surf SDL surface object.
    /////////////////////////////////////////////////
    void operator()(SDL_Surface *surf);

    /////////////////////////////////////////////////
    /// Destroy SDL texture object.
    ///
    /// \param tex SDL texture object.
    /////////////////////////////////////////////////
    void operator()(SDL_Texture *tex);

    /////////////////////////////////////////////////
    /// Destroy SDL font object.
    ///
    /// \param font SDL font object.
    /////////////////////////////////////////////////
    void operator()(TTF_Font *font);
  };
} // namespace journey_of_dreams
