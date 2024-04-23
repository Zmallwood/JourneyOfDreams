#pragma once

namespace zw
{
    class Tile
    {
      public:
        void SetGround(const std::string& groundName);
        auto GroundHash()
        {
            return m_groundHash;
        }

      private:
        int m_groundHash{ 0 };
    };
}