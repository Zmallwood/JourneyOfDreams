// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "ColorF.h"
#include "PointF.h"

namespace journey_of_dreams {
    class Vertex2F {
      public:
        PointF pos;
        ColorF color;
        PointF uv;
    };
}