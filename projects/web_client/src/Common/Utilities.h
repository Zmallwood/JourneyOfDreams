// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/Size.h"

// Utility functions declaration.

namespace journey_of_dreams
{
   /////////////////////////////////////////////////
   /// Return canvas size in pixels.
   ///
   /// \return Size of canvas in pixels.
   /////////////////////////////////////////////////
   Size GetCanvasSize();

   /////////////////////////////////////////////////
   /// Get ratio of canvas width/height.
   ///
   /// \return Aspect ratio of canvas.
   /////////////////////////////////////////////////
   float GetAspectRatio();

   /////////////////////////////////////////////////
   /// Get file extension from file path.
   ///
   /// \param absPath Absolute path to file.
   /// \return File extension.
   /////////////////////////////////////////////////
   std::string FileExtension(const std::string &absPath);
   /////////////////////////////////////////////////
   /// Get file name without extension from file path.
   ///
   /// \param absPath Absolute path to file.
   /// \return File name without extension.
   /////////////////////////////////////////////////
   std::string FilenameNoExtension(const std::string &absPath);

   /////////////////////////////////////////////////
   /// Convert fractal width to corresponding height.
   ///
   /// \param width Fractal width.
   /// \return Fractal height.
   /////////////////////////////////////////////////
   float ConvertWidthToHeight(float width);

   /////////////////////////////////////////////////
   /// Convert fractal height to corresponding width.
   ///
   /// \param height Fractal height.
   /// \return Fractal width.
   /////////////////////////////////////////////////
   float ConvertHeightToWidth(float height);

   /////////////////////////////////////////////////
   /// Get mouse position in canvas in pixels.
   ///
   /// \return Mouse position in canvas in fractal
   ///         values..
   /////////////////////////////////////////////////
   PointF GetMousePosition();
} // namespace journey_of_dreams
