#pragma once

#include "GUIWidget.h"
#include "ManagedTextString.h"

namespace zw {
  class GUITextBox : public GUIWidget {
   public:
    GUITextBox(RectF area, ColorF textColor = Colors::Wheat, bool passwordMode = false);

    void UpdateDerived() override;

    void RenderDerived() override;

    std::string GetText();

    void ClearText();

    void Focus() override;

   private:
    RID m_ridBackground{};
    RID m_ridText{};
    RID m_ridCursorImage{};
    ManagedTextString m_managedTextLine;
    ColorF m_textColor{ Colors::Wheat };
    float m_cursorHeight{ 0.01f };

    const std::string k_cursorImage{ "GUITextBoxCursor" };
    const float k_cursorWidth{ 0.002f };
  };
}
