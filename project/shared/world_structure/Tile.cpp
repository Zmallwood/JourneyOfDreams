#include "Tile.h"

namespace zw
{
    Tile::void SetGround(const std::string &groundName)
    {
        m_groundHash = Hash(groundName);
    }
}