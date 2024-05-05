// Copyright (c) 2024 Andreas Åkerberg.

#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

// Utility functions implementation.

namespace journey_of_dreams
{
   Size
   GetCanvasSize() {
      // to store dimensions in pixelsx
      int w;
      int h;
      // use SDL to get window size = canvas size
      // SDL_GetWindowSize(_<Graphics>().Window().get(), &w, &h);
      glfwGetWindowSize(_<Graphics>().Window(), &w, &h);
      return {w, h};
   }

   float
   GetAspectRatio() {
      // get canvas dimensions
      auto canvasSize = GetCanvasSize();
      // and calculate the ratio between them
      auto aspectRatio = static_cast<float>(canvasSize.w) / canvasSize.h;
      return aspectRatio;
   }

   std::string
   FileExtension(const std::string &absPath) {
      // find last occurrence of '.' and keep the part following it
      auto extension = absPath.substr(absPath.find_last_of('.') + 1);
      return extension;
   }

   std::string
   FilenameNoExtension(const std::string &absPath) {
      // find last occurence of '/' and get the part following it
      auto nameWithExt = absPath.substr(absPath.find_last_of('/') + 1);
      // then only keep the part preceeding the last occurrence of '.'
      auto fileName = nameWithExt.substr(0, nameWithExt.find_last_of('.'));
      return fileName;
   }

   float
   ConvertWidthToHeight(float width) {
      // use aspect ratio to convert from width to corresponding height
      return width * GetAspectRatio();
   }

   float
   ConvertHeightToWidth(float height) {
      // use aspect ratio to convert from height to corresponding width
      return height / GetAspectRatio();
   }

   PointF
   GetMousePosition() {
      double xpos, ypos;
      glfwGetCursorPos(_<Graphics>().Window(), &xpos, &ypos);
      // to store mouse coordinates in pixels
      int x;
      int y;
      // use SDL to get current mouse coordinates
      // SDL_GetMouseState(&x, &y);
      glfwGetWindowPos(_<Graphics>().Window(), &x, &y);
      // get canvas size
      auto canvasSize = GetCanvasSize();
      // and use it to convert pixel coordinates to fractal coordinates
      auto mousePosition = PointF{static_cast<float>(xpos) / canvasSize.w,
                                  static_cast<float>(ypos) / canvasSize.h};
      return mousePosition;
   }
} // namespace journey_of_dreams
