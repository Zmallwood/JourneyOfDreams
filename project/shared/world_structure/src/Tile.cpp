#include "Tile.h"

namespace zw
{
    void Tile::SetGround(const std::string &groundName)
    {
        m_ground = Hash(groundName);
    }

    void Tile::SetGround(int groundHash)
    {
        m_ground = groundHash;
    }
}