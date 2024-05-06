/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "ColorF.h"
#include "PointF.h"

/* Vertex2F class declaration. */

namespace JourneyOfDreams
{
  class Vertex2F {
   public:
    PointF pos;
    ColorF color;
    PointF uv;
  };
}