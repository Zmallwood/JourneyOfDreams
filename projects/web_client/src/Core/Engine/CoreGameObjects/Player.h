#pragma once

namespace zw
{
    class Player
    {
      public:
        Player();
        int GetX();
        int GetY();
        auto Position()
        {
            return m_position;
        }
        void SetPosition(Point position)
        {
            m_position = position;
        }

      private:
        Point m_position{ .x = 0, .y = 0 };
    };
}