#include "MouseButton.h"

namespace JourneyOfDreams
{
    void MouseButton::OnPress()
    { // Set the pressed flag to true.
        m_pressed = true;
    }

    void MouseButton::OnRelease()
    { // Set the pressed flag to false.
        m_pressed = false;
    }

    bool MouseButton::PressedPickResult()
    {
        auto result = m_pressed;
        m_pressed = false;
        return result;
    }

    bool MouseButton::Pressed()
    { // Getter
        return m_pressed;
    }
}