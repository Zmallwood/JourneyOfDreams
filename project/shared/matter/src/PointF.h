#pragma once

namespace zw
{
    class PointF
    {
      public:
        PointF operator+=(const PointF &rhs)
        {
            x += rhs.x;
            y += rhs.y;
            return *this;
        }

        float x{ 0.0f };
        float y = { 0.0f };
    };
}