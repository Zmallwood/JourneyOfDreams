// Copyright (c) 2024 Andreas Åkerberg.

#include "ClientProperties.h"

// ClientProperties class implementation.

namespace journey_of_dreams
{
   Size
   ClientProperties::CanvasSize() const {
      // return canvas size in pixels
      return m_canvasSize;
   }

   ColorF
   ClientProperties::DefaultClearColor() const {
      // return default canvas clear color
      return m_defaultClearColor;
   }

   int
   ClientProperties::NumGridRows() const {
      // return number of grid rows
      return m_numGridRows;
   }
} // namespace journey_of_dreams