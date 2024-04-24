#include "ImageBank.h"

namespace zw
{
    ImageBank::ImageBank()
    {
        LoadImages();
    }

    ImageBank::~ImageBank()
    {
        for (const auto &img : m_images)
            glDeleteTextures(1, &img.second);
    }

    GLuint ImageBank::GetImage(const std::string &imageName)
    {
        for (auto img : m_images)
            if (img.first == Hash(imageName))
                return img.second;

        return -1;
    }

    GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName)
    {
        GLuint texID;
        glGenTextures(1, &texID);
        m_images.insert({ Hash(uniqueImageName), texID });
        
        return texID;
    }

    void ImageBank::LoadImages()
    {
        using iterator = std::filesystem::recursive_directory_iterator;
     
        auto allImagesPath = k_relImagesPath + "/";
     
        for (auto &entry : iterator(allImagesPath))
        {
            auto absPath = entry.path().string();
            if (FileExtension(absPath) != "png")
                continue;
            auto texID = LoadSingleImage(absPath);
            auto imageName = FilenameNoExtension(absPath);
            m_images.insert({ Hash(imageName), texID });
        }
    }

    GLuint ImageBank::LoadSingleImage(const std::string &absFilePath)
    {
        GLuint texID;
        
        auto surf = IMG_Load(absFilePath.data());
        
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &texID);
        glBindTexture(GL_TEXTURE_2D, texID);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        
        if (surf->format->BytesPerPixel == 4)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);
        }
        
        SDL_FreeSurface(surf);
        
        return texID;
    }
}
