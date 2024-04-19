#pragma once

#include "GLRectF.h"

namespace zw
{
    class RectF
    {
      public:
        GLRectF ToGLRectF() const
        {
            return { x * 2 - 1.0f, 1.0f - y * 2, w * 2, h * 2 };
        }

        float x{ 0.0f };
        float y{ 0.0f };
        float w{ 0.0f };
        float h{ 0.0f };
    };
}