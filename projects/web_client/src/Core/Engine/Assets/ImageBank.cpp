#include "ImageBank.h"

namespace JourneyOfDreams
{
    ImageBank::ImageBank()
    {
        //
        // Load all images in images path.
        //
        LoadImages();
    }

    ImageBank::~ImageBank()
    {
        //
        // Iterate through all the loaded images.
        //
        for (const auto &img : m_images)
            //
            // And free every allocated image resource.
            //
            glDeleteTextures(1, &img.second);
    }

    GLuint ImageBank::GetImage(const std::string &imageName)
    {
        //
        // Hash the image name and call the other GetImage method.
        //
        return GetImage(Hash(imageName));
    }

    GLuint ImageBank::GetImage(int imageNameHash)
    {
        //
        // Iterate through all the loaded images.
        //
        for (auto img : m_images)
            //
            // If its key, being the hash of the image name, equals the hash of the specified name.
            //
            if (img.first == imageNameHash)
                //
                // If so, return this image ID.
                //
                return img.second;
        //
        // No image with the name found, return fail value.
        //
        return -1;
    }

    GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName)
    {
        //
        // Generate new image resource and get its ID.and get its ID.
        //
        GLuint texID;
        glGenTextures(1, &texID);

        //
        // Insert new image entry with image name hash as key and the new ID as value.
        //
        m_images.insert({ Hash(uniqueImageName), texID });

        //
        // Return the ID of the newly created blank image resource.
        //
        return texID;
    }

    void ImageBank::LoadImages()
    {
        using iterator = std::filesystem::recursive_directory_iterator;

        //
        // Create path string to load the images from.
        //
        auto allImagesPath = k_relImagesPath + "/";

        for (auto &entry : iterator(allImagesPath))
        {
            auto absPath = entry.path().string();

            //
            // Only handle files with png extenstion.
            //
            if (FileExtension(absPath) != "png")
                continue;

            //
            // Load the current file as an image resource.
            //
            auto texID = LoadSingleImage(absPath);

            //
            // // Extract its pure name without path or extension.
            //
            auto imageName = FilenameNoExtension(absPath);

            //
            // Insert a new entry into the images storage, with the image name hash as key and the resource ID
            // as value.
            //
            m_images.insert({ Hash(imageName), texID });
        }
    }

    GLuint ImageBank::LoadSingleImage(const std::string &absFilePath)
    {
        GLuint texID; // Will hold the resulting ID for the loaded image file.

        auto surf = LoadImageData(absFilePath.data()); // Get image data from the image file.

        glEnable(GL_TEXTURE_2D); // We will work with 2D textures.

        glGenTextures(1, &texID); // Generate a new OpenGL texture and get its ID.

        glBindTexture(GL_TEXTURE_2D, texID); // Use the newly created OpenGL texture.

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                        GL_NEAREST); // Apply necessary texture parameters, mag filter.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                        GL_NEAREST); // Apply necessary texture parameters, min filter.

        if (surf->format->BytesPerPixel == 4) // If image format is RGBA (with alpha channel)
        {
            glTexImage2D( // Transfer image data from SDL surface to OpenGL texture resource.
                GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
        }
        else // If image format is RGB (without alpha channel)
        {
            glTexImage2D( // Transfer image data from SDL surface to OpenGL texture resource.
                GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);
        }

        SDL_FreeSurface(surf); // Free SDL surface resource. Its not needed anymore as the image data is
                               // stored in the OpenGL texture now.

        return texID; // Return the previously generated resource ID.
    }

    SDL_Surface *ImageBank::LoadImageData(const char *filename)
    {
        int width, height, bytesPerPixel;
        void *data = stbi_load(filename, &width, &height, &bytesPerPixel, 0); // Read data

        int pitch;
        pitch = width * bytesPerPixel; // Calculate pitch
        pitch = (pitch + 3) & ~3;      // continue calculation

        int Rmask, Gmask, Bmask, Amask;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN // Setup relevance bitmask, case little endian
        Rmask = 0x000000FF;
        Gmask = 0x0000FF00;
        Bmask = 0x00FF0000;
        Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
#else // Setup relevance bitmask, case other
        int s = (bytesPerPixel == 4) ? 0 : 8;
        Rmask = 0xFF000000 >> s;
        Gmask = 0x00FF0000 >> s;
        Bmask = 0x0000FF00 >> s;
        Amask = 0x000000FF >> s;
#endif
        SDL_Surface *surface = SDL_CreateRGBSurfaceFrom( // Create SDL surface from image data
            data, width, height, bytesPerPixel * 8, pitch, Rmask, Gmask, Bmask, Amask);
        if (!surface) // If surface creation failed
        {
            stbi_image_free(data); // Free image data
            return nullptr;
        }

        return surface; // Return the created SDL surface
    }
}
