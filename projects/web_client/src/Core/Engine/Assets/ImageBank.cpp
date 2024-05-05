// Copyright (c) 2024 Andreas Åkerberg.

#include "ImageBank.h"

// ImageBank class implementation.

namespace journey_of_dreams
{
  ImageBank::ImageBank() {
    // load all images in images path
    LoadImages();
  }

  ImageBank::~ImageBank() {
    // iterate through all the loaded images
    for (const auto &_img : m_images) {
      // and free every allocated image resource
      glDeleteTextures(1, &_img.second);
    }
  }

  GLuint ImageBank::GetImage(const std::string &_imageName) {
    // hash the image name and call the other GetImage method
    return GetImage(Hash(_imageName));
  }

  GLuint ImageBank::GetImage(int _imageNameHash) {
    // iterate through all the loaded images
    for (auto _img : m_images) {
      // if its key, being the hash of the image name, equals the hash of the
      // specified name
      if (_img.first == _imageNameHash) {
        // if so, return this image ID
        return _img.second;
      }
    }
    // no image with the name found, return fail value
    return -1;
  }

  GLuint ImageBank::CreateBlankImage(const std::string &_uniqueImageName) {
    // generate new image resource and get its ID.and get its ID
    GLuint _texID;
    glGenTextures(1, &_texID);
    // insert new image entry with image name hash as key and the new ID as
    // value
    m_images.insert({Hash(_uniqueImageName), _texID});
    // return the ID of the newly created blank image resource
    return _texID;
  }

  void ImageBank::LoadImages() {
    using iterator = std::filesystem::recursive_directory_iterator;
    // create path string to load the images from
    auto _allImagesPath = k_relImagesPath + "/";
    for (auto &_entry : iterator(_allImagesPath)) {
      auto _absPath = _entry.path().string();
      // only handle files with png extenstion
      if (FileExtension(_absPath) != "png") {
        continue;
      }
      // load the current file as an image resource
      auto _texID = LoadSingleImage(_absPath);
      // extract its pure name without path or extension
      auto _imageName = FilenameNoExtension(_absPath);
      // insert a new entry into the images storage, with the image name hash as
      // key and the resource ID as value
      m_images.insert({Hash(_imageName), _texID});
    }
  }

  GLuint ImageBank::LoadSingleImage(const std::string &absFilePath) {
    // will hold the resulting ID for the loaded image file
    GLuint _texID;
    // get image data from the image file
    auto _surf = LoadImageData(absFilePath.c_str());
    // auto surf = IMG_Load(absFilePath.c_str());
    // we will work with 2D textures
    glEnable(GL_TEXTURE_2D);
    // generate a new OpenGL texture and get its ID
    glGenTextures(1, &_texID);
    // use the newly created OpenGL texture
    glBindTexture(GL_TEXTURE_2D, _texID);
    // apply necessary texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // if image format is RGBA (with alpha channel)
    if (_surf->format->BytesPerPixel == 4) {
      // transfer image data from SDL surface to OpenGL texture resource
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _surf->w, _surf->h, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, _surf->pixels);
    }
    // if image format is RGB (without alpha channel)
    else {
      // transfer image data from SDL surface to OpenGL texture resource
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _surf->w, _surf->h, 0, GL_RGB,
                   GL_UNSIGNED_BYTE, _surf->pixels);
    }
    // free SDL surface resource, its not needed anymore as the image data is
    // stored in the OpenGL texture now
    SDL_FreeSurface(_surf);
    // return the previously generated resource ID
    return _texID;
  }

  SDL_Surface *ImageBank::LoadImageData(const char *filename) {
    int _width;
    int _height;
    int _bytesPerPixel;
    // read data
    void *_data = stbi_load(filename, &_width, &_height, &_bytesPerPixel, 0);
    int _pitch;
    // calculate pitch
    _pitch = _width * _bytesPerPixel;
    _pitch = (_pitch + 3) & ~3;
    int _rMask;
    int _gMask;
    int _bMask;
    int _aMask;
    // setup relevance bitmask
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
    // create SDL surface from image data
    SDL_Surface *_surface =
        SDL_CreateRGBSurfaceFrom(_data, _width, _height, _bytesPerPixel * 8, _pitch,
                                 _rMask, _gMask, _bMask, _aMask);
    // if surface creation failed
    if (!_surface) {
      // free image data
      //  stbi_image_free(data);
      return nullptr;
    }
    // Return the created SDL surface
    return _surface;
  }
} // namespace journey_of_dreams
