#pragma once

#include "MouseButton.h"

namespace zw
{
    class MouseInput
    {
      public:
        void OnPress(Uint8 button);
        void OnRelease(Uint8 button);
        bool AnyButtonPressed();
        auto &LeftButton()
        {
            return leftButton;
        }
        auto &RightButton()
        {
            return rightButton;
        }

      private:
        MouseButton leftButton;
        MouseButton rightButton;
    };
}