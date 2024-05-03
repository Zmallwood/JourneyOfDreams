//  Copyright (C) 2024 Andreas Åkerberg

#include "PollEvents.h"
#include "Input/KeyboardInput.h"
#include "Input/MouseInput.h"

namespace JourneyOfDreams
{
    void PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                break;
            case SDL_KEYDOWN:
                _<KeyboardInput>().OnKeyPress(event.key.keysym.sym);

                break;
            case SDL_KEYUP:
                _<KeyboardInput>().OnKeyRelease(event.key.keysym.sym);

                break;
            case SDL_MOUSEBUTTONDOWN:
            std::cout << "down\n";
                // _<MouseInput>().OnPress(event.button.button);

                break;
            case SDL_MOUSEBUTTONUP:
            std::cout << "up\n";
                // _<MouseInput>().OnRelease(event.button.button);

                break;
            case SDL_MOUSEMOTION:
                break;

            case SDL_TEXTINPUT:
                _<KeyboardInput>().AppendTextInput(event.text.text);

                break;
            case SDL_MOUSEWHEEL:

                break;
            }
        }
    }
}