// Copyright (c) 2024 Andreas Åkerberg.

#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

// Utility functions implementation.

namespace journey_of_dreams
{
  Size GetCanvasSize() {
    // To store dimensions in pixels.
    int _w;
    int _h;
    // Use GLFW to get canvas size.
    glfwGetWindowSize(_<Graphics>().Window(), &_w, &_h);
    return {_w, _h};
  }

  float GetAspectRatio() {
    // Get canvas dimensions.
    auto _canvasSize = GetCanvasSize();
    // And calculate the ratio between them.
    auto _aspectRatio = static_cast<float>(_canvasSize.w) / _canvasSize.h;
    return _aspectRatio;
  }

  std::string FileExtension(const std::string &_absPath) {
    // Find last occurrence of '.' and keep the part following it.
    auto _extension = _absPath.substr(_absPath.find_last_of('.') + 1);
    return _extension;
  }

  std::string FilenameNoExtension(const std::string &_absPath) {
    // Find last occurence of '/' and get the part following it.
    auto _nameWithExt = _absPath.substr(_absPath.find_last_of('/') + 1);
    // Then only keep the part preceeding the last occurrence of '.'.
    auto _fileName = _nameWithExt.substr(0, _nameWithExt.find_last_of('.'));
    return _fileName;
  }

  float ConvertWidthToHeight(float _width) {
    // Use aspect ratio to convert from width to corresponding height.
    return _width * GetAspectRatio();
  }

  float ConvertHeightToWidth(float _height) {
    // Use aspect ratio to convert from height to corresponding width.
    return _height / GetAspectRatio();
  }

  PointF GetMousePosition() {
    double _xpos, _ypos;
    glfwGetCursorPos(_<Graphics>().Window(), &_xpos, &_ypos);
    // To store mouse coordinates in pixels.
    int _x;
    int _y;
    // Use GLFW to get current mouse coordinates.
    glfwGetWindowPos(_<Graphics>().Window(), &_x, &_y);
    // Get canvas size.
    auto _canvasSize = GetCanvasSize();
    // And use it to convert pixel coordinates to fractal coordinates.
    auto _mousePosition = PointF{static_cast<float>(_xpos) / _canvasSize.w,
                                 static_cast<float>(_ypos) / _canvasSize.h};
    return _mousePosition;
  }
} // namespace journey_of_dreams
