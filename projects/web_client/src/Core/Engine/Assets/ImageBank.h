#pragma once

#include <SDL_opengles2.h>
#include <map>

struct SDL_Surface;

namespace zw
{
    class ImageBank
    {
      public:
        void LoadImages();

      private:
        SDL_Surface *LoadImage(const char *filename);
    };
}
