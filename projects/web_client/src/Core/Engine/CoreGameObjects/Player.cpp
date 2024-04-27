#include "Player.h"
#include "configuration/src/GlobalProperties.h"

namespace zw
{
    Player::Player()
    {
        auto worldAreaSize = _<GlobalProperties>().WorldAreaSize();
        m_position = { .x = worldAreaSize.w / 2, .y = worldAreaSize.h / 2 };
    }

    int Player::GetX()
    {
        return m_position.x;
    }

    int Player::GetY()
    {
        return m_position.y;
    }
}