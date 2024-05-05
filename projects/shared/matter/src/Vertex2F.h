//  Copyright (C) 2024 Andreas Åkerberg

#pragma once
#include "ColorF.h"
#include "PointF.h"

namespace JourneyOfDreams {
    class Vertex2F {
      public:
        PointF pos;
        ColorF color;
        PointF uv;
    };
}