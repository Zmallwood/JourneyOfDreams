#include "ImageBank.h"
#include <SDL_image.h>

namespace zw
{
    void ImageBank::LoadImages()
    {
        std::string absPath = "GroundGrass.png";

        // GLuint texID;

        auto surf = SDL_LoadBMP(absPath.c_str()); 
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
        //                 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE,
        //                              surf->pixels);
        //             }
        //         }

        //         SDL_FreeSurface(surf);
        //     }
        // }

        // glBindTexture(GL_TEXTURE_2D, 0);
    }
}
