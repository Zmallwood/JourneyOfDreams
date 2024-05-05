//  Copyright (C) 2024 Andreas Åkerberg

#pragma once
#include <SDL2/SDL.h>

namespace JourneyOfDreams {
    class ColorF {
      public:
        SDL_Color ToSDLColor(void) const {
            return { static_cast<unsigned char>(r * 255), static_cast<unsigned char>(g * 255),
                     static_cast<unsigned char>(b * 255), static_cast<unsigned char>(a * 255) };
        }

        float r{ 0.0f };
        float g{ 0.0f };
        float b{ 0.0f };
        float a{ 1.0f };
    };
}