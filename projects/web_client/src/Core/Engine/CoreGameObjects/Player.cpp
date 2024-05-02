//  Copyright (C) 2024 Andreas Åkerberg

#include "Player.h"
#include "configuration/src/GlobalProperties.h"

namespace JourneyOfDreams
{
    Player::Player()
    {
        /*
        ** Initialize player position to the center of the world area. */
        auto worldAreaSize = _<GlobalProperties>().WorldAreaSize();
        m_position = { .x = worldAreaSize.w / 2, .y = worldAreaSize.h / 2 };
    }

    int Player::GetX()
    {
        /*
        ** Return player x position. */
        return m_position.x;
    }

    int Player::GetY()
    {
        /*
        ** Return player y position. */
        return m_position.y;
    }

    void Player::MoveNorth()
    {
        /*
        ** Move player north. */
        m_position.y -= 1;
    }

    void Player::MoveEast()
    {
        /*
        ** Move player east. */
        m_position.x += 1;
    }

    void Player::MoveSouth()
    {
        /*
        ** Move player south. */
        m_position.y += 1;
    }

    void Player::MoveWest()
    {
        /*
        ** Move player west. */
        m_position.x -= 1;
    }

    Point Player::Position()
    {
        /*
        ** Getter */
        return m_position;
    }

    void Player::SetPosition(Point position)
    {
        /*
        ** Setter */
        m_position = position;
    }

    int Player::TicksLastMove()
    {
        /*
        ** Getter */
        return m_ticksLastMove;
    }

    void Player::SetTicksLastMove(int ticksLastMove)
    {
        /*
        ** Setter */
        m_ticksLastMove = ticksLastMove;
    }

    float Player::MovementSpeed()
    {
        /*
        ** Getter */
        return m_movementSpeed;
    }

    Point Player::Destination()
    {
        /*
        ** Getter */
        return m_destination;
    }

    void Player::SetDestination(Point destination)
    {
        /*
        ** Setter */
        m_destination = destination;
    }
}