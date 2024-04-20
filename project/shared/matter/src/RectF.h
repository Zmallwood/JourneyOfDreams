#pragma once

#include "GLRectF.h"
#include "PointF.h"
#include "SizeF.h"

namespace zw
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

        float x{ 0.0f };
        float y{ 0.0f };
        float w{ 0.0f };
        float h{ 0.0f };
    };
}