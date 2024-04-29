#pragma once

namespace JourneyOfDreams
{
    class MouseButton
    {
      public:
        void OnPress();

        void OnRelease();

        bool PressedPickResult();

        auto Pressed()
        {
            return m_pressed;
        }

      private:
        bool m_pressed{ false };
    };
}
