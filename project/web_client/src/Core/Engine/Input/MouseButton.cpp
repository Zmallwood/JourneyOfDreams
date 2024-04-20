#include "MouseButton.h"

namespace zw
{
    void MouseButton::OnPress()
    {
        m_pressed = true;
    }
    void MouseButton::OnRelease()
    {
        m_pressed = false;
    }
}