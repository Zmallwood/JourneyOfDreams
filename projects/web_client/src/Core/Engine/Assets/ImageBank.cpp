//
//  Copyright (C) 2024 Andreas Åkerberg
//
#include "ImageBank.h"
//
//  ImageBank class implementation.
//
namespace JourneyOfDreams
{
   ImageBank::ImageBank() {
      //load all images in images path
      LoadImages();
   }
   ImageBank::~ImageBank() {
      //iterate through all the loaded images
      for (const auto &img : m_images) {
         //and free every allocated image resource
         glDeleteTextures(1, &img.second);
      }
   }
   GLuint ImageBank::GetImage(const std::string &imageName) {
      //hash the image name and call the other GetImage method
      return GetImage(Hash(imageName));
   }
   GLuint ImageBank::GetImage(int imageNameHash) {
      //iterate through all the loaded images
      for (auto img : m_images) {
         //if its key, being the hash of the image name, equals the hash of the specified name
         if (img.first == imageNameHash) {
            //if so, return this image ID
            return img.second;
         }
      }
      //no image with the name found, return fail value
      return -1;
   }
   GLuint ImageBank::CreateBlankImage(const std::string &uniqueImageName) {
      //generate new image resource and get its ID.and get its ID
      GLuint texID;
      glGenTextures(1, &texID);
      //insert new image entry with image name hash as key and the new ID as value
      m_images.insert({ Hash(uniqueImageName), texID });
      //return the ID of the newly created blank image resource
      return texID;
   }
   void ImageBank::LoadImages() {
      using iterator = std::filesystem::recursive_directory_iterator;
      //create path string to load the images from
      auto allImagesPath = k_relImagesPath + "/";
      for (auto &entry : iterator(allImagesPath)) {
         auto absPath = entry.path().string();
         //only handle files with png extenstion
         if (FileExtension(absPath) != "png") {
            continue;
         }
         //load the current file as an image resource
         auto texID = LoadSingleImage(absPath);
         //extract its pure name without path or extension
         auto imageName = FilenameNoExtension(absPath);
         //insert a new entry into the images storage, with the image name hash as key and the resource ID
         //as value
         m_images.insert({ Hash(imageName), texID });
      }
   }
   GLuint ImageBank::LoadSingleImage(const std::string &absFilePath) {
      //will hold the resulting ID for the loaded image file
      GLuint texID;
      //get image data from the image file
      auto surf = LoadImageData(absFilePath.c_str());
      //auto surf = IMG_Load(absFilePath.c_str());
      //we will work with 2D textures
      glEnable(GL_TEXTURE_2D);
      //generate a new OpenGL texture and get its ID
      glGenTextures(1, &texID);
      //use the newly created OpenGL texture
      glBindTexture(GL_TEXTURE_2D, texID);
      //apply necessary texture parameters
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      //if image format is RGBA (with alpha channel)
      if (surf->format->BytesPerPixel == 4) {
         //transfer image data from SDL surface to OpenGL texture resource
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                      surf->pixels);
      }
      //if image format is RGB (without alpha channel)
      else {
         //transfer image data from SDL surface to OpenGL texture resource
         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);
      }
      //free SDL surface resource, its not needed anymore as the image data is stored in the OpenGL texture
      //now
      SDL_FreeSurface(surf);
      //return the previously generated resource ID
      return texID;
   }
   SDL_Surface *ImageBank::LoadImageData(const char *filename) {
      int width;
      int height;
      int bytesPerPixel;
      //read data
      void *data = stbi_load(filename, &width, &height, &bytesPerPixel, 0);
      int pitch;
      //calculate pitch
      pitch = width * bytesPerPixel;
      pitch = (pitch + 3) & ~3;
      int Rmask;
      int Gmask;
      int Bmask;
      int Amask;
      //setup relevance bitmask
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
      //create SDL surface from image data
      SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(data, width, height, bytesPerPixel * 8, pitch, Rmask,
                                                      Gmask, Bmask, Amask);
      //if surface creation failed
      if (!surface) {
         //free image data
         // stbi_image_free(data);
         return nullptr;
      }
      // Return the created SDL surface
      return surface;
   }
} // namespace JourneyOfDreams
