#pragma once

namespace zw
{
    class Engine;

    class TileHoverer
    {
      public:
        TileHoverer(Engine &engine);
        void Update();
        auto HoveredCoordinate() const
        {
            return m_hoveredCoordinate;
        }

      private:
        Point m_hoveredCoordinate{ -1, -1 };
        Engine &m_engine;
    };
}