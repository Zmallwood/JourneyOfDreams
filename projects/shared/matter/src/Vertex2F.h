//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

#include "PointF.h"
#include "ColorF.h"

namespace JourneyOfDreams
{
    class Vertex2F
    {
      public:
        PointF pos;
        ColorF color;
        PointF uv;
    };
}