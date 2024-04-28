#pragma once

#include "GUIPanel.h"

namespace zw
{
    class OnScreenKeyboard : public GUIPanel
    {
      public:
        OnScreenKeyboard(zw::Engine& engine);
        void Initialize() override;
        void Show();
        void Hide();

      private:
        void TypeCharacter(char c);
    };
}