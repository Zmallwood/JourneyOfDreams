//  Copyright (C) 2024 Andreas Åkerberg

#include "ImageBank.h"
#include <png.h>
// #define STB_IMAGE_IMPLEMENTATION
// #include <SDL_image.h>

// #include <stb_image.h>

namespace JourneyOfDreams
{
    typedef union RGBA
    {
        std::uint32_t Colour;
        struct
        {
            std::uint8_t R, G, B, A;
        };
    } *PRGB;

    void ReadFromStream(png_structp PngPointer, std::uint8_t *Data, std::size_t Length)
    {
        std::ifstream *Stream = reinterpret_cast<std::ifstream *>(png_get_io_ptr(PngPointer));
        Stream->read(reinterpret_cast<char *>(Data), Length);
    }

    void LoadPngImage(const char *FilePath, std::vector<RGBA> &Pixels, std::uint32_t &width,
                      std::uint32_t &height, std::uint16_t &BitsPerPixel)
    {
        Pixels.clear();
        std::fstream hFile(FilePath, std::ios::in | std::ios::binary);

        if (!hFile.is_open())
        {
            throw std::invalid_argument("File Not Found.");
        }

        std::uint8_t Header[18] = { 0 };
        hFile.read(reinterpret_cast<char *>(&Header), sizeof(Header));
        hFile.seekg(8, std::ios::beg);

        if (png_sig_cmp(Header, 0, 8))
        {
            hFile.close();
            throw std::invalid_argument("Error: Invalid File Format. Required: Png.");
        }

        png_structp PngPointer = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
        if (!PngPointer)
        {
            hFile.close();
            throw std::runtime_error("Error: Cannot Create Read Structure.");
        }

        png_infop InfoPointer = png_create_info_struct(PngPointer);
        if (!InfoPointer)
        {
            hFile.close();
            png_destroy_read_struct(&PngPointer, nullptr, nullptr);
            throw std::runtime_error("Error: Cannot Create InfoPointer Structure.");
        }

        png_infop EndInfo = png_create_info_struct(PngPointer);
        if (!EndInfo)
        {
            hFile.close();
            png_destroy_read_struct(&PngPointer, &InfoPointer, nullptr);
            throw std::runtime_error("Error: Cannot Create EndInfo Structure.");
        }

        if (setjmp(png_jmpbuf(PngPointer)))
        {
            hFile.close();
            png_destroy_read_struct(&PngPointer, &InfoPointer, nullptr);
            throw std::runtime_error("Error: Cannot Set Jump Pointer.");
        }

        png_set_sig_bytes(PngPointer, 8);
        png_set_read_fn(PngPointer, &hFile, ReadFromStream);
        png_read_info(PngPointer, InfoPointer);

        auto channels = png_get_channels(PngPointer, InfoPointer);

        int bitdepth, colortype, interlacetype;
        png_get_IHDR(PngPointer, InfoPointer, &width, &height, &bitdepth, &colortype, &interlacetype, nullptr,
                     nullptr);
        png_set_interlace_handling(PngPointer);
        png_set_strip_16(PngPointer);
        png_set_packing(PngPointer);

        switch (colortype)
        {
        case PNG_COLOR_TYPE_GRAY:
        {
            png_set_expand_gray_1_2_4_to_8(PngPointer);
            png_set_gray_to_rgb(PngPointer);
            png_set_bgr(PngPointer);
            break;
        }

        case PNG_COLOR_TYPE_PALETTE:
        {
            png_set_palette_to_rgb(PngPointer);
            if (png_get_valid(PngPointer, InfoPointer, PNG_INFO_tRNS))
                png_set_tRNS_to_alpha(PngPointer);
            else
                png_set_filler(PngPointer, 0xFF, PNG_FILLER_AFTER);
            png_set_bgr(PngPointer);
            BitsPerPixel = 24;
            break;
        }

        case PNG_COLOR_TYPE_GRAY_ALPHA:
        {
            png_set_gray_to_rgb(PngPointer);
            break;
        }

        case PNG_COLOR_TYPE_RGB:
        {
            png_set_bgr(PngPointer);
            png_set_filler(PngPointer, 0xFF, PNG_FILLER_AFTER);
            BitsPerPixel = 24;
            break;
        }

        case PNG_COLOR_TYPE_RGBA:
        {
            png_set_bgr(PngPointer);
            BitsPerPixel = 32;
            break;
        }

        default:
            png_destroy_read_struct(&PngPointer, &InfoPointer, nullptr);
            throw std::runtime_error("Error: Png Type not supported.");
            break;
        }

        png_read_update_info(PngPointer, InfoPointer);
        channels = png_get_channels(PngPointer, InfoPointer);

        // int bitdepth, colortype, interlacetype;
        png_get_IHDR(PngPointer, InfoPointer, &width, &height, &bitdepth, &colortype, &interlacetype, nullptr,
                     nullptr);

        Pixels.resize(width * height);
        std::vector<std::uint8_t *> RowPointers(height);
        std::uint8_t *BuffPos = reinterpret_cast<std::uint8_t *>(Pixels.data());

        for (size_t I = 0; I < height; ++I)
        {
            RowPointers[I] = BuffPos + (I * width * sizeof(RGBA));
        }

        png_read_image(PngPointer, RowPointers.data());
        png_read_end(PngPointer, InfoPointer);
        png_destroy_read_struct(&PngPointer, &InfoPointer, nullptr);
        hFile.close();
    }

    ImageBank::ImageBank()
    {
        /*
        ** Load all images in images path. */
        LoadImages();
    }

    ImageBank::~ImageBank()
    {
        /*
        ** Iterate through all the loaded images. */
        for (const auto &img : m_images)
        {
            /*
            ** And free every allocated image resource. */
            glDeleteTextures(1, &img.second);
        }
    }

    GLuint ImageBank::GetImage(const std::string &imageName)
    {
        /*
        ** Hash the image name and call the other GetImage method. */
        return GetImage(Hash(imageName));
    }

    GLuint ImageBank::GetImage(int imageNameHash)
    {
        /*
        ** Iterate through all the loaded images. */
        for (auto img : m_images)
        {
            /*
            ** If its key, being the hash of the image name, equals the hash of the specified name. */
            if (img.first == imageNameHash)
            {
                /*
                ** If so, return this image ID. */
                return img.second;
            }
        }
        /*
        ** No image with the name found, return fail value. */
        return -1;
    }

    GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName)
    {
        /*
        ** Generate new image resource and get its ID.and get its ID. */
        GLuint texID;
        glGenTextures(1, &texID);
        /*
        ** Insert new image entry with image name hash as key and the new ID as value. */
        m_images.insert({ Hash(uniqueImageName), texID });
        /*
        ** Return the ID of the newly created blank image resource. */
        return texID;
    }

    void ImageBank::LoadImages()
    {
        using iterator = std::filesystem::recursive_directory_iterator;

        /*
        ** Create path string to load the images from. */
        auto allImagesPath = k_relImagesPath + "/";

        for (auto &entry : iterator(allImagesPath))
        {
            auto absPath = entry.path().string();
            /*
            ** Only handle files with png extenstion. */
            if (FileExtension(absPath) != "png")
            {
                continue;
            }
            /*
            ** Load the current file as an image resource. */
            auto texID = LoadSingleImage(absPath);

            /*
            ** Extract its pure name without path or extension. */
            auto imageName = FilenameNoExtension(absPath);
            /*
            ** Insert a new entry into the images storage, with the image name hash as key and the resource ID
            ** as value. */
            m_images.insert({ Hash(imageName), texID });
        }
    }

    GLuint ImageBank::LoadSingleImage(const std::string &absFilePath)
    {
        /*
        ** Will hold the resulting ID for the loaded image file. */
        GLuint texID;

        /*
        ** Get image data from the image file. */
        auto surf = LoadImageData(absFilePath.c_str());
        // auto surf = IMG_Load(absFilePath.c_str());
        /*
        ** We will work with 2D textures. */
        glEnable(GL_TEXTURE_2D);
        /*
        ** Generate a new OpenGL texture and get its ID. */
        glGenTextures(1, &texID);
        /*
        ** Use the newly created OpenGL texture. */
        glBindTexture(GL_TEXTURE_2D, texID);
        /*
        ** Apply necessary texture parameters */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        /*
        ** If image format is RGBA (with alpha channel) */
        if (surf->format->BytesPerPixel == 4)
        {
            /*
            ** Transfer image data from SDL surface to OpenGL texture resource. */
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                         surf->pixels);
        }
        /*
        ** If image format is RGB (without alpha channel) */
        else
        {
            /*
            ** Transfer image data from SDL surface to OpenGL texture resource. */
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE,
                         surf->pixels);
        }
        /*
        ** Free SDL surface resource. Its not needed anymore as the image data is stored in the OpenGL texture
        ** now. */
        SDL_FreeSurface(surf);
        /*
        ** Return the previously generated resource ID. */
        return texID;
    }

    SDL_Surface *ImageBank::LoadImageData(const char *filename)
    {
                int width;
                int height;
                int bytesPerPixel;
                /*
                ** Read data */
                void *data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);

                int pitch;
                /*
                ** Calculate pitch */
                pitch = width * bytesPerPixel;
                pitch = (pitch + 3) & ~3;

                int Rmask;
                int Gmask;
                int Bmask;
                int Amask;
                /*
                ** Setup relevance bitmask */
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
//         std::vector<RGBA> pixels;
//         std::uint32_t width, height;
//         std::uint16_t bitsperpixel;
//         LoadPngImage(filename, pixels, width, height, bitsperpixel);

//         auto bytesPerPixel = bitsperpixel * 8;
//         int pitch;
//         /*
//         ** Calculate pitch */
//         pitch = width * bytesPerPixel;
//         pitch = (pitch + 3) & ~3;

//         int Rmask;
//         int Gmask;
//         int Bmask;
//         int Amask;
//         /*
//         ** Setup relevance bitmask */
// #if SDL_BYTEORDER == SDL_LIL_ENDIAN
//         Rmask = 0x000000FF;
//         Gmask = 0x0000FF00;
//         Bmask = 0x00FF0000;
//         Amask = (bytesPerPixel == 4) ? 0xFF000000 : 0;
// #else
//         int s = (bytesPerPixel == 4) ? 0 : 8;
//         Rmask = 0xFF000000 >> s;
//         Gmask = 0x00FF0000 >> s;
//         Bmask = 0x0000FF00 >> s;
//         Amask = 0x000000FF >> s;
//#endif

        /*
        ** Create SDL surface from image data */
        //SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(pixels.data(), width, height, bitsperpixel, pitch,
         //                                               Rmask, Gmask, Bmask, Amask);
         SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(data, width, height, bytesPerPixel * 8, pitch,
         Rmask,
                                                         Gmask, Bmask, Amask);
        // stbi_image_free(data);
        /*
        ** If surface creation failed */
        if (!surface)
        {
            /*
            ** Free image data */
            // stbi_image_free(data);

            return nullptr;
        }
        /*
        ** Return the created SDL surface */
        return surface;
    }
}
