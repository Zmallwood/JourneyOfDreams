// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "ColorF.h"
#include "PointF.h"

// vertex2f class declaration.

namespace journey_of_dreams
{
  class Vertex2F {
   public:
    PointF pos;
    ColorF color;
    PointF uv;
  };
} // namespace journey_of_dreams