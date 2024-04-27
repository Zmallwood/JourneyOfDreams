#pragma once

namespace zw
{
    /// Loads and provides images loaded from the file system.
    class ImageBank
    {
      public:
        /// Initializes bank by loading all images in images folder.
        ImageBank();

        /// Frees all allocated OpenGL image resources.
        // Emscripten: destructors appearantly not called => cannot cleanup
        // ~ImageBank();

        /// Provides the image with the specified name.
        GLuint GetImage(const std::string &imageName);

        GLuint GetImage(int imageNameHash);

        /// Creates a blank image resource, given the specified name, and returns its ID.
        GLuint CreateBlankImage(const std::string &uniqueImageName);

        /// Load all images from file system in the images path.
        void LoadImages();

      private:

        /// Load a single image at the path and return its resource ID.
        GLuint LoadSingleImage(const std::string &absFilePath);

        /// Internal image storage.
        std::shared_ptr<std::map<int, GLuint>> m_images;

        /// Path to the images folder, relative the applications base path.
        const std::string k_relImagesPath = "images";
    };
}
