#pragma once

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
typedef struct _TTF_Font TTF_Font;

namespace zw
{
    class SDLDeleter
    {
      public:
        /// Destroy window object.
        void operator()(SDL_Window *window);

        /// Destroy renderer object.
        void operator()(SDL_Renderer *renderer);

        /// Destroy surface object.
        void operator()(SDL_Surface *surface);

        /// Destroy texture object.
        void operator()(SDL_Texture *texture);

        /// Destroy font object.
        void operator()(TTF_Font *font);
    };
}
