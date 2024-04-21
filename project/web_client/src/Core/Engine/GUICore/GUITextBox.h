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
        std::string m_text{};
        ColorF m_textColor{ Colors::Black };
    };
}