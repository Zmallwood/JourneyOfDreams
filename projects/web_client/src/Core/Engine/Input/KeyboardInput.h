#pragma once

namespace zw
{
    class KeyboardInput
    {
      public:
        void OnKeyPress(SDL_Keycode key);

        void OnKeyRelease(SDL_Keycode key);

        bool AnyKeyIsPressed();

        bool KeyIsPressed(SDL_Keycode key);

        bool KeyHasBeenFiredPickResult(SDL_Keycode key);

        void AppendTextInput(const std::string &text);

        std::string PickTextInput();

        void ClearTextInput();

      private:
        // std::set<SDL_Keycode> m_pressedKeys;
        std::string m_textInput;
    };
}
