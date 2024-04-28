#include "ImageBank.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stb_image.h>


namespace zw
{
    SDL_Surface *ImageBank::LoadImage(const char *filename)
    {
        // Read data
        int width, height, bytesPerPixel;
        void *data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);

        // Calculate pitch
        int pitch;
        pitch = width * bytesPerPixel;
        pitch = (pitch + 3) & ~3;

        // Setup relevance bitmask
        int Rmask, Gmask, Bmask, Amask;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
        Rmask = 0x000000FF;
        Gmask = 0x0000FF00;
        Bmask = 0x00FF0000;
        Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
#else
        int s = (bytesPerPixel == 4) ? 0 : 8;
        Rmask = 0xFF000000 >> s;
        Gmask = 0x00FF0000 >> s;
        Bmask = 0x0000FF00 >> s;
        Amask = 0x000000FF >> s;
#endif
        SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(data, width, height, bytesPerPixel * 8, pitch, Rmask,
                                                        Gmask, Bmask, Amask);
        if (!surface)
        {
            // NOTE: Should free stbi_load 'data' variable here
            return NULL;
        }
        return surface;
    }

    void ImageBank::LoadImages() 
    {
        std::string absPath = "GroundGrass.png";

        // GLuint texID;

        //auto surf = SDL_LoadBMP(absPath.c_str());
        auto surf = LoadImage(absPath.c_str());
        // glGenTextures(1, &texID);
        // glEnable(GL_TEXTURE_2D);

        // if (texID)
        // {
        //     glBindTexture(GL_TEXTURE_2D, texID);

        //     if (surf)
        //     {
        //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        //         if (surf->format)
        //         {
        //             if (surf->format->BytesPerPixel == 4)
        //             {
        //                 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA,
        //                              GL_UNSIGNED_BYTE, surf->pixels);
        //             }
        //             else
        //             {
        //                 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB,
        //                 GL_UNSIGNED_BYTE,
        //                              surf->pixels);
        //             }
        //         }

        //         SDL_FreeSurface(surf);
        //     }
        // }

        // glBindTexture(GL_TEXTURE_2D, 0);
    }
}
