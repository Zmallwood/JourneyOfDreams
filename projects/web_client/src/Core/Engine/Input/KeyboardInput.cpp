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

    bool KeyboardInput::KeyIsPressed(SDL_Keycode key)
    {
        return m_pressedKeys.contains(key);
    }

    bool KeyboardInput::KeyHasBeenFiredPickResult(SDL_Keycode key)
    {
        auto result = m_pressedKeys.contains(key);
        m_pressedKeys.erase(key);
        return result;
    }

    void KeyboardInput::AppendTextInput(const std::string &text)
    {
        m_textInput += text;
    }

    std::string KeyboardInput::PickTextInput()
    {
        auto result = m_textInput;
        m_textInput.clear();
        return result;
    }

    void KeyboardInput::ClearTextInput()
    {
        m_textInput.clear();
    }
}