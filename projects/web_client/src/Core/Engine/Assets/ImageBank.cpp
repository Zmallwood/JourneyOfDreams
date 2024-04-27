#include "ImageBank.h"
#include "Core/Engine/Graphics/Graphics.h"

namespace zw
{
    ImageBank::ImageBank()
    {
        _<Graphics>(); // Touch Graphics to ensure the graphics, with the GL context, is initialized.

        // Load all images in images path.
        LoadImages();
    }

    // ImageBank::~ImageBank()
    // {
    //     if (m_images.empty())
    //         return;

    //     // Iterate through all the loaded images.
    //     for (const auto &img : m_images)
    //         // And free every allocated image resource.
    //         glDeleteTextures(1, &img.second);
    // }

    GLuint ImageBank::GetImage(const std::string &imageName)
    {
        return GetImage(Hash(imageName));
    }

    GLuint ImageBank::GetImage(int imageNameHash)
    {
        // Iterate through all the loaded images.
        for (auto img : m_images)
            // If its key, being the hash of the image name, equals the hash of the specified name.
            if (img.first == imageNameHash)
                // If so, return this image ID.
                return img.second;

        // No image with the name found, return fail value.
        return -1;
    }

    GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName)
    {
        // Generate new image resource and get its ID.
        GLuint texID;
        glGenTextures(1, &texID);

        // Insert new image entry with image name hash as key and the new ID as value.
        m_images.insert({ Hash(uniqueImageName), texID });

        // Return the ID of the newly created blank image resource.
        return texID;
    }

    void ImageBank::LoadImages()
    {
        using iterator = std::filesystem::directory_iterator;

        // Create path string to load the images from.
        auto allImagesPath = k_relImagesPath + "/";

        for (auto &entry : iterator(allImagesPath))
        {
            auto absPath = entry.path().string();

            // Only handle files with png extenstion.
            if (FileExtension(absPath) != "png")
                continue;

            // Do the atual loading of the image file.
            auto texID = LoadSingleImage(absPath);

            // Extract its pure name without path or extension.
            auto imageName = FilenameNoExtension(absPath);

            // Insert a new entry into the images storage,
            // with the image name hash as key and the resource ID as value.
            //m_images.insert({ Hash(imageName), texID });
        }
    }

    GLuint ImageBank::LoadSingleImage(const std::string &absFilePath)
    {
        IMG_Init(IMG_INIT_PNG);

        // Will hold the resulting ID for the loaded image file.
        GLuint texID;

        if (std::filesystem::exists(absFilePath))
        {
            // Get image data from the image file.
            auto surf = IMG_Load(absFilePath.c_str());

            // // Generate a new OpenGL texture and get its ID.
            glGenTextures(1, &texID);

            // We will work with 2D textures.
            glEnable(GL_TEXTURE_2D);

            // Use the newly created OpenGL texture.
            if (texID)  
            {
                glBindTexture(GL_TEXTURE_2D, texID);

                // // Determine image format.
                if (surf)
                {
                    // Apply necessary texture parameters.
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

                    if (surf->format)
                    {
                        if (surf->format->BytesPerPixel == 4)
                        // RGBA (with alpha channel)
                        {
                            // Transfer image data from SDL surface to OpenGL texture resource.
                            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA,
                            GL_UNSIGNED_BYTE,
                                         surf->pixels);
                        }
                        else
                        // RGB (without alpha channel)
                        {
                            // Transfer image data from SDL surface to OpenGL texture resource.
                            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB,
                            GL_UNSIGNED_BYTE,
                                         surf->pixels);
                        }
                    }

                    // Free SDL surface resource. Its not needed anymore
                    // as the image data is stored in the OpenGL texture now.
                    SDL_FreeSurface(surf);
                }
            }

            glBindTexture(GL_TEXTURE_2D, 0);
        }
        // // Return the previously generated resource ID.
        return texID;
    }
}
