#pragma once

namespace zw
{
    class TileHoverer
    {
      public:
        void Update();
        auto HoveredCoordinate() const
        {
            return m_hoveredCoordinate;
        }

      private:
        Point m_hoveredCoordinate{ -1, -1 };
    };
}