/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* ImageBank class declaration. */

namespace journey_of_dreams
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
    /// \param _imageName Name of the image to get.
    /// \return Image resource ID.
    /////////////////////////////////////////////////
    GLuint GetImage(const std::string &_imageName);

    /////////////////////////////////////////////////
    /// Gets an image resource by hash code.
    ///
    /// \param _imageNameHash Hash code of the image to get.
    /// \return Image resource ID.
    /////////////////////////////////////////////////
    GLuint GetImage(int _imageNameHash);

    /////////////////////////////////////////////////
    /// Creates a blank image resource, given
    /// the specified name, and returns its ID.
    ///
    /// \param _uniqueImageName Name of the image to create.
    /// \return Image resource ID.
    /////////////////////////////////////////////////
    GLuint CreateBlankImage(const std::string &_uniqueImageName);

   private:
    void LoadImages();
    GLuint LoadSingleImage(const std::string &_absFilePath);
    SDL_Surface *LoadImageData(const char *_filename);
    std::map<int, GLuint> m_images;
    const std::string k_relImagesPath = "images";
  };
}