//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

#include "MouseButton.h"

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Manages the mouse input.
    /////////////////////////////////////////////////
    class MouseInput
    {
      public:
        /////////////////////////////////////////////////
        /// Called when a mouse button is pressed.
        /////////////////////////////////////////////////
        void OnPress(Uint8 button);

        /////////////////////////////////////////////////
        /// Called when a mouse button is released.
        /////////////////////////////////////////////////
        void OnRelease(Uint8 button);

        /////////////////////////////////////////////////
        /// Tells if any button is pressed.
        ///
        /// \return True if any button is pressed.
        /////////////////////////////////////////////////
        bool AnyButtonPressed();

        /////////////////////////////////////////////////
        /// Getter (by reference) for the left mouse button.
        ///
        /// \return Reference to the left mouse button.
        /////////////////////////////////////////////////
        MouseButton &LeftButton();

        /////////////////////////////////////////////////
        /// Getter (by reference) for the right mouse button.
        ///
        /// \return Reference to the right mouse button.
        /////////////////////////////////////////////////
        MouseButton &RightButton();

      private:
        MouseButton leftButton;
        MouseButton rightButton;
    };
}
