#pragma once

namespace zw
{
    class Player
    {
      public:
        Player();
        int GetX();
        int GetY();
        void MoveNorth();
        void MoveEast();
        void MoveSouth();
        void MoveWest();
        auto Position()
        {
            return m_position;
        }
        void SetPosition(Point position)
        {
            m_position = position;
        }
        auto TicksLastMove()
        {
            return m_ticksLastMove;
        }
        void SetTicksLastMove(int ticksLastMove)
        {
            m_ticksLastMove = ticksLastMove;
        }
        auto MovementSpeed()
        {
            return m_movementSpeed;
        }
        auto Destination()
        {
            return m_destination;
        }
        void SetDestination(Point destination)
        {
            m_destination = destination;
        }

      private:
        Point m_position{ .x = 0, .y = 0 };
        int m_ticksLastMove{ 0 };
        float m_movementSpeed{ 3.0f };
        Point m_destination{ .x = -1, .y = -1 };
    };
}