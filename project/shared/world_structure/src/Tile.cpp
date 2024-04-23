#include "Tile.h"

namespace zw
{
    void Tile::SetGround(const std::string &groundName)
    {
        m_groundHash = Hash(groundName);
    }
}