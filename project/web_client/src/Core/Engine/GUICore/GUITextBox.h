#pragma once

#include "GUIWidget.h"

namespace zw
{
    class GUITextBox : public GUIWidget
    {
      public:
        GUITextBox(RectF area, ColorF textColor = Colors::Black);
        void UpdateDerived() override;
        void RenderDerived() override;

      private:
        RID m_ridBackground{};
        RID m_ridText{};
        RID m_ridCursorImage{};
        std::string m_text{};
        ColorF m_textColor{ Colors::Black };
        int m_cursorPosition{ 0 };
        const std::string k_cursorImage{ "GUITextBoxCursor" };
        float m_cursorHeight{ 0.01f };
        const float k_cursorWidth{ 0.004f };
    };
}