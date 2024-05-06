/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

/* Utility functions implementation. */

namespace JourneyOfDreams
{
  Size GetCanvasSize() {
    /* 1) To store dimensions in pixels.
     * 2) Use GLFW to get canvas size. */
    int w;
    int h;
    glfwGetWindowSize(_<Graphics>().Window(), &w, &h);
    return {w, h};
  }

  float GetAspectRatio() {
    /* 1) Get canvas dimensions.
     * 2) And calculate the ratio between them. */
    auto canvasSize = GetCanvasSize();
    auto aspectRatio = static_cast<float>(canvasSize.w) / canvasSize.h;
    return aspectRatio;
  }

  std::string FileExtension(const std::string &absPath) {
    /* Find last occurrence of '.' and keep the part following it. */
    auto extension = absPath.substr(absPath.find_last_of('.') + 1);
    return extension;
  }

  std::string FilenameNoExtension(const std::string &absPath) {
    /* 1) Find last occurence of '/' and get the part following it.
     * 2) Then only keep the part preceeding the last occurrence of '.'. */
    auto nameWithExt = absPath.substr(absPath.find_last_of('/') + 1);
    auto fileName = nameWithExt.substr(0, nameWithExt.find_last_of('.'));
    return fileName;
  }

  float ConvertWidthToHeight(float width) {
    /* Use aspect ratio to convert from width to corresponding height. */
    return width * GetAspectRatio();
  }

  float ConvertHeightToWidth(float height) {
    /* Use aspect ratio to convert from height to corresponding width. */
    return height / GetAspectRatio();
  }

  PointF GetMousePosition() {
    /* 1) Declare variables to store mouse coordinates in pixels.
     * 2) Use GLFW to get current mouse coordinates.
     * 3) Get canvas size.
     * 4) And use it to convert pixel coordinates to fractal coordinates. */
    double xpos, ypos;
    glfwGetCursorPos(_<Graphics>().Window(), &xpos, &ypos);
    int x;
    int y;
    glfwGetWindowPos(_<Graphics>().Window(), &x, &y);
    auto canvasSize = GetCanvasSize();
    auto mousePosition = PointF{static_cast<float>(xpos) / canvasSize.w,
                                 static_cast<float>(ypos) / canvasSize.h};
    return mousePosition;
  }
}
