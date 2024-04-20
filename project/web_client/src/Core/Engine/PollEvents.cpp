#include "PollEvents.h"
#include "Input/KeyboardInput.h"
#include "Input/MouseInput.h"

namespace zw
{
    void PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                //_<Engine>().SetIsRunning(false);

                break;
            case SDL_KEYDOWN:
                _<KeyboardInput>().OnKeyPress(event.key.keysym.sym);

                break;
            case SDL_KEYUP:
                _<KeyboardInput>().OnKeyRelease(event.key.keysym.sym);

                break;
            case SDL_MOUSEBUTTONDOWN:
                _<MouseInput>().OnPress(event.button.button);

                break;
            case SDL_MOUSEBUTTONUP:
                _<MouseInput>().OnRelease(event.button.button);

                break;
            case SDL_MOUSEMOTION:
                break;

            case SDL_TEXTINPUT:
                //_<KeyboardInput>().AppendTextInput(event.text.text);

                break;
            case SDL_MOUSEWHEEL:
                //_<MouseInput>().OnMouseWheel(event.wheel.y);

                break;
            }
        }
    }
}