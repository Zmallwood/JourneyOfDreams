#pragma once

#include "GLRectF.h"
#include "PointF.h"
#include "SizeF.h"

namespace JourneyOfDreams
{
    class RectF
    {
      public:
        GLRectF ToGLRectF() const
        {
            return { x * 2 - 1.0f, 1.0f - y * 2, w * 2, h * 2 };
        }
        PointF GetPosition() const
        {
            return { x, y };
        }
        SizeF GetSize() const
        {
            return { w, h };
        }
        bool Contains(PointF point) const
        {
            return point.x >= x && point.x <= x + w && point.y >= y && point.y <= y + h;
        }

        float x{ 0.0f };
        float y{ 0.0f };
        float w{ 0.0f };
        float h{ 0.0f };
    };
}