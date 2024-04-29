#include "Player.h"
#include "configuration/src/GlobalProperties.h"

namespace JourneyOfDreams
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

    Point Player::Position()
    {
        return m_position;
    }
    
    void Player::SetPosition(Point position)
    {
        m_position = position;
    }

    int Player::TicksLastMove()
    {
        return m_ticksLastMove;
    }

    void Player::SetTicksLastMove(int ticksLastMove)
    {
        m_ticksLastMove = ticksLastMove;
    }

    float Player::MovementSpeed()
    {
        return m_movementSpeed;
    }

    Point Player::Destination()
    {
        return m_destination;
    }

    void Player::SetDestination(Point destination)
    {
        m_destination = destination;
    }
}