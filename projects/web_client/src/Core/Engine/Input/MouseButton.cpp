#include "MouseButton.h"

namespace JourneyOfDreams
{
    void MouseButton::OnPress()
    {
        m_pressed = true;
    }

    void MouseButton::OnRelease()
    {
        m_pressed = false;
    }

    bool MouseButton::PressedPickResult()
    {
        auto result = m_pressed;
        m_pressed = false;
        return result;
    }
}