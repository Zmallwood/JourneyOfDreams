// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// mouse_button class declaration.

namespace journey_of_dreams
{
  /////////////////////////////////////////////////
  /// Manages mouse button input.
  /////////////////////////////////////////////////
  class MouseButton {
   public:
    /////////////////////////////////////////////////
    /// Called when the button is pressed.
    /////////////////////////////////////////////////
    void OnPress();

    /////////////////////////////////////////////////
    /// Called when the button is released.
    /////////////////////////////////////////////////
    void OnRelease();

    /////////////////////////////////////////////////
    /// Tells if the button has been pressed, and
    /// resets the state of the button so that
    /// proceeding calls will return false.
    ///
    /// \return True if the button has been pressed.
    /////////////////////////////////////////////////
    bool PressedPickResult();

    /////////////////////////////////////////////////
    /// Tells if the button is pressed.
    ///
    /// \return True if the button is pressed.
    /////////////////////////////////////////////////
    bool Pressed();

   private:
    bool m_pressed{false};
  };
} // namespace journey_of_dreams
