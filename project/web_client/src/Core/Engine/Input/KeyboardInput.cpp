#include "KeyboardInput.h"

namespace zw
{
    void KeyboardInput::OnKeyPress(SDL_Keycode key)
    {
        m_pressedKeys.insert(key);
    }

    void KeyboardInput::OnKeyRelease(SDL_Keycode key)
    {
        m_pressedKeys.erase(key);
    }

    bool KeyboardInput::AnyKeyIsPressed()
    {
        return m_pressedKeys.size() > 0;
    }
}