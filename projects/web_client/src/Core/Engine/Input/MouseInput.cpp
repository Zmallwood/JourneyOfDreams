#include "MouseInput.h"

namespace zw
{
    void MouseInput::OnPress(Uint8 button)
    {
        if (button == SDL_BUTTON_LEFT)
        {
            leftButton.OnPress();
        }
        else if (button == SDL_BUTTON_RIGHT)
        {
            rightButton.OnPress();
        }
    }

    void MouseInput::OnRelease(Uint8 button)
    {
        if (button == SDL_BUTTON_LEFT)
        {
            leftButton.OnRelease();
        }
        else if (button == SDL_BUTTON_RIGHT)
        {
            rightButton.OnRelease();
        }
    }

    bool MouseInput::AnyButtonPressed()
    {
        return leftButton.Pressed() || rightButton.Pressed();
    }
}