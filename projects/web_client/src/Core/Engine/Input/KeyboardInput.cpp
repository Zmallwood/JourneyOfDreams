#include "KeyboardInput.h"

namespace JourneyOfDreams
{
    void KeyboardInput::OnKeyPress(SDL_Keycode key)
    { // Add the key to the set of pressed keys.
        m_pressedKeys.insert(key);
    }

    void KeyboardInput::OnKeyRelease(SDL_Keycode key)
    { // Remove the key from the set of pressed keys.
        m_pressedKeys.erase(key);
    }

    bool KeyboardInput::AnyKeyIsPressed()
    { // Return true if any key is pressed.
        return m_pressedKeys.size() > 0;
    }

    bool KeyboardInput::KeyIsPressed(SDL_Keycode key)
    { // Return true if the key is pressed.
        return m_pressedKeys.contains(key);
    }

    bool KeyboardInput::KeyHasBeenFiredPickResult(SDL_Keycode key)
    {
        auto result = m_pressedKeys.contains(key);
        m_pressedKeys.erase(key);
        return result;
    }

    void KeyboardInput::AppendTextInput(const std::string &text)
    { // Append text to the text input buffer.
        m_textInput += text;
    }

    std::string KeyboardInput::PickTextInput()
    {
        auto result = m_textInput;
        m_textInput.clear();
        return result;
    }

    void KeyboardInput::ClearTextInput()
    { // Clear the text input buffer.
        m_textInput.clear();
    }
}