/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* ImageBank class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Loads and provides images that has
  /// been loaded from the filesystem.
  /////////////////////////////////////////////////
  class ImageBank {
   public:
    /////////////////////////////////////////////////
    /// Initializes bank by loading all images
    /// in images folder.
    /////////////////////////////////////////////////
    ImageBank();

    /////////////////////////////////////////////////
    /// Frees all allocated OpenGL image resources.
    /////////////////////////////////////////////////
    ~ImageBank();

    /////////////////////////////////////////////////
    /// Gets an image resource by name.
    ///
    /// @param imageName Name of the image to get.
    /// @return Image resource ID.
    /////////////////////////////////////////////////
    GLuint GetImage(const std::string &imageName);

    /////////////////////////////////////////////////
    /// Gets an image resource by hash code.
    ///
    /// @param imageNameHash Hash code of the image to get.
    /// @return Image resource ID.
    /////////////////////////////////////////////////
    GLuint GetImage(int imageNameHash);

    /////////////////////////////////////////////////
    /// Creates a blank image resource, given
    /// the specified name, and returns its ID.
    ///
    /// @param uniqueImageName Name of the image to create.
    /// @return Image resource ID.
    /////////////////////////////////////////////////
    GLuint CreateBlankImage(const std::string &uniqueImageName);

   private:
    void LoadImages();
    GLuint LoadSingleImage(const std::string &absFilePath);
    SDL_Surface *LoadImageData(const char *filename);
    std::map<int, GLuint> m_images;
    const std::string k_relImagesPath {"images"};
  };
}