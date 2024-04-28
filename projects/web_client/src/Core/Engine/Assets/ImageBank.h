#pragma once

#include <map>
#include <SDL_opengles2.h>

namespace zw
{
    class ImageBank
    {
      public:
        void LoadImages();

      private:
        GLuint LoadSingleImage(std::string absFilePath);

        std::shared_ptr<std::map<int, GLuint>> m_images;

        const std::string k_relImagesPath = "images";
    };
}
