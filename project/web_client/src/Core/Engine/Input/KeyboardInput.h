#pragma once

namespace zw
{
    class KeyboardInput
    {
      public:
        void OnKeyPress(SDL_Keycode key);
        void OnKeyRelease(SDL_Keycode key);
        bool AnyKeyIsPressed();

      private:
        std::set<SDL_Keycode> m_pressedKeys;
    };
}