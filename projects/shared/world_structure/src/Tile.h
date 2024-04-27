#pragma once

namespace zw
{
    class Tile
    {
      public:
        void SetGround(const std::string &groundName);
        void SetGround(int groundHash);
        bool IsWalkable();
        auto Ground()
        {
            return m_ground;
        }
        auto Elevation()
        {
            return m_elevation;
        }

      private:
        int m_ground{ 0 };
        float m_elevation{ 0.0f };
    };
}