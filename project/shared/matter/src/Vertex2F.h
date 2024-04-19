#pragma once

#include "PointF.h"
#include "ColorF.h"

namespace zw
{
    class Vertex2F
    {
      public:
        PointF pos;
        ColorF color;
        PointF uv;
    };
}