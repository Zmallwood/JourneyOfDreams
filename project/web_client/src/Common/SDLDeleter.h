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
        void operator()(SDL_Window *window);

        void operator()(SDL_Renderer *renderer);

        void operator()(SDL_Surface *surface);

        void operator()(SDL_Texture *texture);

        void operator()(TTF_Font *font);
    };
}
