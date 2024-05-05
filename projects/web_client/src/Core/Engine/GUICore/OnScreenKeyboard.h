// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIPanel.h"

// on_screen_keyboard class declaration.

namespace journey_of_dreams
{
  /////////////////////////////////////////////////
  /// A GUI panel that displays an on-screen
  /// keyboard for text input on touch devices.
  /////////////////////////////////////////////////
  class OnScreenKeyboard : public GUIPanel {
   public:
    /////////////////////////////////////////////////
    /// Makes the keyboard invisible by default
    /// and sets the padding to 0.
    /////////////////////////////////////////////////
    OnScreenKeyboard();

    /////////////////////////////////////////////////
    /// Creates all the sub widgets.
    /////////////////////////////////////////////////
    void Initialize() override;

    /////////////////////////////////////////////////
    /// Shows the keyboard.
    /////////////////////////////////////////////////
    void Show();

    /////////////////////////////////////////////////
    /// Hides the keyboard.
    /////////////////////////////////////////////////
    void Hide();

   private:
    void TypeCharacter(char c);
  };
} // namespace journey_of_dreams