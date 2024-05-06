/* Copyright (c) 2024 Andreas Åkerberg. */

#include "ClientProperties.h"

/* ClientProperties class implementation. */

namespace journey_of_dreams
{
  Size ClientProperties::CanvasSize() const {
    return m_canvasSize;
  }

  ColorF ClientProperties::DefaultClearColor() const {
    return m_defaultClearColor;
  }

  int ClientProperties::NumGridRows() const {
    return m_numGridRows;
  }
} // namespace journey_of_dreams