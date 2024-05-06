/* Copyright (c) 2024 Andreas Åkerberg. */

#include "KeyboardInput.h"

/* KeyboardInput class implementation. */

namespace JourneyOfDreams
{
  void KeyboardInput::OnKeyPress(int key) {
    /*
    ** Add the key to the set of pressed keys.*/
    m_pressedKeys.insert(key);
  }

  void KeyboardInput::OnKeyRelease(int key) {
    /*
    ** Remove the key from the set of pressed keys. */
    m_pressedKeys.erase(key);
  }

  bool KeyboardInput::AnyKeyIsPressed() {
    /*
    ** Return true if any key is pressed. */
    return m_pressedKeys.size() > 0;
  }

  bool KeyboardInput::KeyIsPressed(int key) {
    /*
    ** Return true if the key is pressed. */
    return m_pressedKeys.contains(key);
  }

  bool KeyboardInput::KeyHasBeenFiredPickResult(int key) {
    /*
    ** Pick out result. */
    auto result = m_pressedKeys.contains(key);
    /*
    ** Reset state. */
    m_pressedKeys.erase(key);
    /*
    ** Return result. */
    return result;
  }

  void KeyboardInput::AppendTextInput(const std::string &text) {
    /*
    ** Append text to the text input buffer. */
    m_textInput += text;
  }

  std::string KeyboardInput::PickTextInput() {
    /*
    ** Pick out result. */
    auto result = m_textInput;
    /*
    ** Reset state. */
    m_textInput.clear();
    /*
    ** Return result. */
    return result;
  }

  void KeyboardInput::ClearTextInput() {
    /*
    ** Clear the text input buffer. */
    m_textInput.clear();
  }
}