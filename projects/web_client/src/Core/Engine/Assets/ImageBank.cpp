#include "ImageBank.h"

namespace JourneyOfDreams
{
    ImageBank::ImageBank()
    {
        //
        // Load all images in images path.
        LoadImages();
    }

    ImageBank::~ImageBank()
    {
        //
        // Iterate through all the loaded images.
        for (const auto &img : m_images)
            //
            // And free every allocated image resource.
            glDeleteTextures(1, &img.second);
    }

    GLuint ImageBank::GetImage(const std::string &imageName)
    {
        //
        // Hash the image name and call the other GetImage method.
        return GetImage(Hash(imageName));
    }

    GLuint ImageBank::GetImage(int imageNameHash)
    {
        //
        // Iterate through all the loaded images.
        for (auto img : m_images)
            //
            // If its key, being the hash of the image name, equals the hash of the specified name.
            if (img.first == imageNameHash)
                //
                // If so, return this image ID.
                return img.second;
        //
        // No image with the name found, return fail value.
        return -1;
    }

    GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName)
    {
        //
        // Generate new image resource and get its ID.and get its ID.
        GLuint texID;
        glGenTextures(1, &texID);

        //
        // Insert new image entry with image name hash as key and the new ID as value.
        m_images.insert({ Hash(uniqueImageName), texID });

        //
        // Return the ID of the newly created blank image resource.
        return texID;
    }

    void ImageBank::LoadImages()
    {
        using iterator = std::filesystem::recursive_directory_iterator;

        //
        // Create path string to load the images from.
        auto allImagesPath = k_relImagesPath + "/";

        for (auto &entry : iterator(allImagesPath))
        {
            auto absPath = entry.path().string();

            //
            // Only handle files with png extenstion.
            if (FileExtension(absPath) != "png")
                continue;

            //
            // Load the current file as an image resource.
            auto texID = LoadSingleImage(absPath);

            //
            // Extract its pure name without path or extension.
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
        //
        // Will hold the resulting ID for the loaded image file.
        GLuint texID;

        //
        // Get image data from the image file.
        auto surf = LoadImageData(absFilePath.data());

        //
        // We will work with 2D textures.
        glEnable(GL_TEXTURE_2D);

        //
        // Generate a new OpenGL texture and get its ID.
        glGenTextures(1, &texID);

        //
        // Use the newly created OpenGL texture.
        glBindTexture(GL_TEXTURE_2D, texID);

        //
        // Apply necessary texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        //
        // If image format is RGBA (with alpha channel)
        if (surf->format->BytesPerPixel == 4)
        {
            //
            // Transfer image data from SDL surface to OpenGL texture resource.
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                         surf->pixels);
        }
        //
        // If image format is RGB (without alpha channel)
        else
        {
            //
            // Transfer image data from SDL surface to OpenGL texture resource.
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE,
                         surf->pixels);
        }

        //
        // Free SDL surface resource. Its not needed anymore as the image data is stored in the OpenGL texture
        // now.
        SDL_FreeSurface(surf);

        //
        // Return the previously generated resource ID.
        return texID;
    }

    SDL_Surface *ImageBank::LoadImageData(const char *filename)
    {
        int width;
        int height;
        int bytesPerPixel;

        //
        // Read data
        void *data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);

        int pitch;

        //
        // Calculate pitch
        pitch = width * bytesPerPixel;
        pitch = (pitch + 3) & ~3;

        int Rmask;
        int Gmask;
        int Bmask;
        int Amask;

        //
        // Setup relevance bitmask
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

        //
        // Create SDL surface from image data
        SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(data, width, height, bytesPerPixel * 8, pitch, Rmask,
                                                        Gmask, Bmask, Amask);

        //
        // If surface creation failed
        if (!surface)
        {
            //
            // Free image data
            stbi_image_free(data);

            return nullptr;
        }

        //
        // Return the created SDL surface
        return surface;
    }
}
