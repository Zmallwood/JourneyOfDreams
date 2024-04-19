#pragma once

namespace zw
{
    class ImageBank
    {
      public:
        ImageBank();
        ~ImageBank();
        GLuint GetImage(const std::string& imageName);
        void CreateBlankImage(const std::string& uniqueImageName);

      private:
        void LoadImages();
        GLuint LoadSingleImage(const std::string& absFilePath);

        const std::string k_relImagesPath = "images";
        std::map<int, GLuint> m_images;
    };
}