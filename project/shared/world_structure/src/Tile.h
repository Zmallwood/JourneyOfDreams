#pragma once

namespace zw
{
    class Tile
    {
      public:
        void SetGround(const std::string &groundName);
        auto GroundHash()
        {
            return m_groundHash;
        }
        auto Elevation()
        {
            return m_elevation;
        }

      private:
        int m_groundHash{ 0 };
        float m_elevation{ 0.0f };
    };
}