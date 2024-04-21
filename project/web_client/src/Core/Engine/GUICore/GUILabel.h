#pragma once

#include "Core/Engine/Rendering/TextRendering/FontSizes.h"
#include "GUIWidget.h"

namespace zw
{
    class GUILabel : public GUIWidget
    {
      public:
        GUILabel(PointF position, const std::string &text, GUIAlign alignment = GUIAlign::TopLeft,
                 FontSizes fontSize = FontSizes::_20, ColorF textColor = Colors::Wheat);
        void UpdateDerived() override;
        void RenderDerived() override;
        PointF GetAlignedAbsolutePosition() override;
        void SetText(const std::string &text)
        {
            m_text = text;
        }

      private:
        std::string m_text;
        FontSizes m_fontSize;
        ColorF m_textColor{ Colors::Wheat };
        RID m_ridText{};
    };
}
