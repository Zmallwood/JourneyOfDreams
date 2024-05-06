/* Copyright (c) 2024 Andreas Åkerberg. */

#include "MouseInput.h"

/* MouseInput class implementation. */

namespace JourneyOfDreams
{
  void MouseInput::OnPress(Uint8 button) {
    /*
    ** Forward call to correct button. */
    if (button == SDL_BUTTON_LEFT) {
      leftButton.OnPress();
    } else if (button == SDL_BUTTON_RIGHT) {
      rightButton.OnPress();
    }
  }

  void MouseInput::OnRelease(Uint8 button) {
    /*
    ** Forward call to correct button. */
    if (button == SDL_BUTTON_LEFT) {
      leftButton.OnRelease();
    } else if (button == SDL_BUTTON_RIGHT) {
      rightButton.OnRelease();
    }
  }

  bool MouseInput::AnyButtonPressed() {
    /*
    ** Return true if either button is pressed. */
    return leftButton.Pressed() || rightButton.Pressed();
  }

  MouseButton &MouseInput::LeftButton() {
    /*
    ** Getter by reference */
    return leftButton;
  }

  MouseButton &MouseInput::RightButton() {
    /*
    ** Getter by reference */
    return rightButton;
  }
}