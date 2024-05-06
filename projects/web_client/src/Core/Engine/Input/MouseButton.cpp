/* Copyright (c) 2024 Andreas Åkerberg. */

#include "MouseButton.h"

/* MouseButton class implementation. */

namespace JourneyOfDreams
{
  void MouseButton::OnPress() {
    /*
    ** Set the pressed flag to true. */
    m_pressed = true;
  }

  void MouseButton::OnRelease() {
    /*
    ** Set the pressed flag to false. */
    m_pressed = false;
  }

  bool MouseButton::PressedPickResult() {
    /*
    ** Pick out result. */
    auto result = m_pressed;
    /*
    ** Reset state. */
    m_pressed = false;
    /*
    ** Return result. */
    return result;
  }

  bool MouseButton::Pressed() {
    /*
    ** Getter */
    return m_pressed;
  }
}