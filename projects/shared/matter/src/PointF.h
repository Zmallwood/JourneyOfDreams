/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* PointF class declaration. */

namespace JourneyOfDreams
{
  class PointF {
   public:
    PointF operator+=(const PointF &rhs) {
      x += rhs.x;
      y += rhs.y;
      return *this;
    }

    PointF operator-(const PointF &rhs) const {
      return PointF{x - rhs.x, y - rhs.y};
    }

    float x{0.0f};
    float y = {0.0f};
  };
}