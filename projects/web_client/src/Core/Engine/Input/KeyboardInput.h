// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// keyboard_input class declaration.

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Manaages keyboard input.
  /////////////////////////////////////////////////
  class KeyboardInput {
   public:
    /////////////////////////////////////////////////
    /// Called when a key is pressed.
    ///
    /// \param key The key that was pressed.
    /////////////////////////////////////////////////
    void OnKeyPress(int key);

    /////////////////////////////////////////////////
    /// Called when a key is released.
    ///
    /// \param key The key that was released.
    /////////////////////////////////////////////////
    void OnKeyRelease(int key);

    /////////////////////////////////////////////////
    /// Tells if any key is pressed.
    ///
    /// \return True if any key is pressed.
    /////////////////////////////////////////////////
    bool AnyKeyIsPressed();

    /////////////////////////////////////////////////
    /// Tells if a certain key is pressed.
    ///
    /// \param key The key to check.
    /// \return True if the key is pressed.
    /////////////////////////////////////////////////
    bool KeyIsPressed(int key);

    /////////////////////////////////////////////////
    /// Tells if a certain key has been fired, and
    /// resets the state of the key so that proceeding
    /// calls will return false.
    ///
    /// \param key The key to check.
    /// \return True if the key has been fired.
    /////////////////////////////////////////////////
    bool KeyHasBeenFiredPickResult(int key);

    /////////////////////////////////////////////////
    /// Appends text input to the text input buffer.
    ///
    /// \param text The text to append.
    /////////////////////////////////////////////////
    void AppendTextInput(const std::string &text);

    /////////////////////////////////////////////////
    /// Picks the text input buffer and clears it so
    /// that proceeding calls will return an empty
    /// string.
    ///
    /// \return The text input buffer.
    /////////////////////////////////////////////////
    std::string PickTextInput();

    /////////////////////////////////////////////////
    /// Clears the text input buffer.
    /////////////////////////////////////////////////
    void ClearTextInput();

   private:
    std::set<int> m_pressedKeys;
    std::string m_textInput;
  };
} // namespace JourneyOfDreams
