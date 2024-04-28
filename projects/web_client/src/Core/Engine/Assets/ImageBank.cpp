#include "ImageBank.h"
#include "Common/Hash.h"
#include "Common/Utilities.h"
#include <SDL_image.h>
#include <filesystem>
namespace zw
{
    void ImageBank::LoadImages()
    {
        std::string absPath = "GroundGrass.png";

        auto texID = LoadSingleImage(absPath);

        // Extract its pure name without path or extension.
        auto imageName = FilenameNoExtension(absPath);

        // Insert a new entry into the images storage,
        // with the image name hash as key and the resource ID as value.
        m_images->insert({ Hash(imageName), texID });

        // using iterator = std::filesystem::directory_iterator;

        // // Create path string to load the images from.
        // auto allImagesPath = k_relImagesPath + "/";

        // for (auto &entry : iterator(allImagesPath))
        // {
        //     auto absPath = entry.path().string();

        //     // Only handle files with png extenstion.
        //     if (FileExtension(absPath) != "png")
        //         continue;

        //     // Do the atual loading of the image file.
        //     auto texID = LoadSingleImage(absPath);

        //     // Extract its pure name without path or extension.
        //     auto imageName = FilenameNoExtension(absPath);

        //     // Insert a new entry into the images storage,
        //     // with the image name hash as key and the resource ID as value.
        //     m_images->insert({ Hash(imageName), texID });
        // }
    }

    GLuint ImageBank::LoadSingleImage(std::string absFilePath)
    {
        IMG_Init(IMG_INIT_PNG);

        GLuint texID;

        if (std::filesystem::exists(absFilePath))
        {
            auto surf = IMG_Load(absFilePath.c_str());

            glGenTextures(1, &texID);

            glEnable(GL_TEXTURE_2D);

            if (texID)
            {
                glBindTexture(GL_TEXTURE_2D, texID);

                if (surf)
                {
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

                    if (surf->format)
                    {
                        if (surf->format->BytesPerPixel == 4)
                        {
                            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA,
                                         GL_UNSIGNED_BYTE, surf->pixels);
                        }
                        else
                        {
                            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB,
                                         GL_UNSIGNED_BYTE, surf->pixels);
                        }
                    }

                    SDL_FreeSurface(surf);
                }
            }

            glBindTexture(GL_TEXTURE_2D, 0);
        }
        return texID;
    }
}
