#include "Player.h"
#include "configuration/src/GlobalProperties.h"

namespace zw
{
    Player::Player()
    {
        //auto worldAreaSize = _<GlobalProperties>().WorldAreaSize();
        //m_position = { .x = worldAreaSize.w / 2, .y = worldAreaSize.h / 2 };
    }

    int Player::GetX()
    {
        return m_position.x;
    }

    int Player::GetY()
    {
        return m_position.y;
    }

    void Player::MoveNorth()
    {
        m_position.y -= 1;
    }

    void Player::MoveEast()
    {
        m_position.x += 1;
    }

    void Player::MoveSouth()
    {
        m_position.y += 1;
    }

    void Player::MoveWest()
    {
        m_position.x -= 1;
    }
}