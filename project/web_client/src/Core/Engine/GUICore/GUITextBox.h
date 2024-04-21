#pragma once

#include "GUIWidget.h"
#include "ManagedTextLine.h"

namespace zw
{
    class GUITextBox : public GUIWidget
    {
      public:
        GUITextBox(RectF area, ColorF textColor = Colors::Wheat, bool passwordMode = false);
        void UpdateDerived() override;
        void RenderDerived() override;

      private:
        RID m_ridBackground{};
        RID m_ridText{};
        RID m_ridCursorImage{};
        ManagedTextLine m_managedTextLine;
        ColorF m_textColor{ Colors::Wheat };
        const std::string k_cursorImage{ "GUITextBoxCursor" };
        float m_cursorHeight{ 0.01f };
        bool m_passwordMode{ false };
        const float k_cursorWidth{ 0.002f };
    };
}