//
//  Copyright (C) 2024 Andreas Åkerberg.
//
#pragma once
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;
//
//  SDLDeleter class declaration.
//
namespace JourneyOfDreams
{
   class SDLDeleter {
    public:
      /////////////////////////////////////////////////
      /// Destroy SDL window object.
      ///
      /// \param window SDL window object.
      /////////////////////////////////////////////////
      void operator()(SDL_Window *window);
      /////////////////////////////////////////////////
      /// estroy SDL renderer object.
      ///
      /// \param renderer SDL renderer object.
      /////////////////////////////////////////////////
      void operator()(SDL_Renderer *renderer);
      /////////////////////////////////////////////////
      /// Destroy SDL surface object.
      ///
      /// \param surface SDL surface object.
      /////////////////////////////////////////////////
      void operator()(SDL_Surface *surface);
      /////////////////////////////////////////////////
      /// Destroy SDL texture object.
      ///
      /// \param texture SDL texture object.
      /////////////////////////////////////////////////
      void operator()(SDL_Texture *texture);
      /////////////////////////////////////////////////
      /// Destroy SDL font object.
      ///
      /// \param font SDL font object.
      /////////////////////////////////////////////////
      void operator()(TTF_Font *font);
   };
} // namespace JourneyOfDreams
