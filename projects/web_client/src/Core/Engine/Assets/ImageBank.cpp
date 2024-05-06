/* Copyright (c) 2024 Andreas Åkerberg. */

#include "ImageBank.h"

/* ImageBank class implementation. */

namespace journey_of_dreams
{
  ImageBank::ImageBank() {
    /* Load all images in images path. */
    LoadImages();
  }

  ImageBank::~ImageBank() {
    /* 1) Iterate through all the loaded images.
     * 2) Free every allocated image resource */
    for (const auto &_img : m_images) {
      glDeleteTextures(1, &_img.second);
    }
  }

  GLuint ImageBank::GetImage(const std::string &_imageName) {
    /* Hash the image name and call the other GetImage method. */
    return GetImage(Hash(_imageName));
  }

  GLuint ImageBank::GetImage(int _imageNameHash) {
    /* 1) Iterate through all the loaded images.
     * 2) If its key, being the hash of the image name, equals
     *       the hash of the specified name,
     *       then, return this image ID
     * 3) No image with the name found, return fail value. */
    for (auto _img : m_images) {
      if (_img.first == _imageNameHash) {
        return _img.second;
      }
    }
    return -1;
  }

  GLuint ImageBank::CreateBlankImage(const std::string &_uniqueImageName) {
    /* 1) Generate new image resource and get its ID.
     * 2) Insert new image entry with image name hash as key
     *    and the new ID as value.
     * 3) return the ID of the newly created blank image resource.*/
    GLuint _texID;
    glGenTextures(1, &_texID);
    m_images.insert({Hash(_uniqueImageName), _texID});
    return _texID;
  }

  void ImageBank::LoadImages() {
    /* 1) Create path string to load the images from.
     * 2) Only handle files with png extenstion.
     * 3) Load the current file as an image resource.
     * 4) Extract its pure name without path or extension.
     * 5) Insert a new entry into the images storage, with the
     *    image name hash as key and the resource ID as value.*/
    using iterator = std::filesystem::recursive_directory_iterator;
    auto _allImagesPath = k_relImagesPath + "/";
    for (auto &_entry : iterator(_allImagesPath)) {
      auto _absPath = _entry.path().string();
      if (FileExtension(_absPath) != "png") {
        continue;
      }
      auto _texID = LoadSingleImage(_absPath);
      auto _imageName = FilenameNoExtension(_absPath);
      m_images.insert({Hash(_imageName), _texID});
    }
  }

  GLuint ImageBank::LoadSingleImage(const std::string &absFilePath) {
    /* 1) Declare variable to hold the resulting ID for the loaded image file.
     * 2) Get image data from the image file.
     * 3) We will work with 2D textures.
     * 4) Generate a new OpenGL texture and get its ID.
     * 5) Use the newly created OpenGL texture.
     * 6) Apply necessary texture parameters. */
    GLuint _texID;
    auto _surf = LoadImageData(absFilePath.c_str());
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &_texID);
    glBindTexture(GL_TEXTURE_2D, _texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    /* 1) if image format is RGBA (with alpha channel),
     *    then transfer image data from SDL surface to OpenGL texture resource.
     *    Else if image format is RGB (without alpha channel),
     *    then transfer image data from SDL surface to OpenGL texture resource.
     * 2) Free SDL surface resource, its not needed anymore as the image data is
     *    stored in the OpenGL texture now.
     * 3) Return the previously generated resource ID. */
    if (_surf->format->BytesPerPixel == 4) {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _surf->w, _surf->h, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, _surf->pixels);
    } else {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _surf->w, _surf->h, 0, GL_RGB,
                   GL_UNSIGNED_BYTE, _surf->pixels);
    }
    SDL_FreeSurface(_surf);
    return _texID;
  }

  SDL_Surface *ImageBank::LoadImageData(const char *filename) {
    /* 1) Read data.
     * 2) Calculate pitch.
     * 3) Setup relevance bitmask.
     * 4) Create SDL surface from image data.
     * 5) If surface creation failed, then free image data and return nullptr.
     * 6) Else if surface creation was successful, return the surface. */
    int _width;
    int _height;
    int _bytesPerPixel;
    void *_data = stbi_load(filename, &_width, &_height, &_bytesPerPixel, 0);
    int _pitch;
    _pitch = _width * _bytesPerPixel;
    _pitch = (_pitch + 3) & ~3;
    int _rMask;
    int _gMask;
    int _bMask;
    int _aMask;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    _rMask = 0x000000FF;
    _gMask = 0x0000FF00;
    _bMask = 0x00FF0000;
    _aMask = (_bytesPerPixel == 4) ? 0xFF000000 : 0;
#else
    int s = (bytesPerPixel == 4) ? 0 : 8;
    _rMask = 0xFF000000 >> s;
    _gMask = 0x00FF0000 >> s;
    _bMask = 0x0000FF00 >> s;
    _aMask = 0x000000FF >> s;
#endif
    SDL_Surface *_surface =
        SDL_CreateRGBSurfaceFrom(_data, _width, _height, _bytesPerPixel * 8,
                                 _pitch, _rMask, _gMask, _bMask, _aMask);
    if (!_surface) {
      stbi_image_free(data);
      return nullptr;
    }
    return _surface;
  }
}