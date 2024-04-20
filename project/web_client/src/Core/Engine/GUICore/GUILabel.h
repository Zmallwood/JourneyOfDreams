#pragma once

#include "Core/Engine/Rendering/TextRendering/FontSizes.h"
#include "GUIWidget.h"

namespace zw
{
    class GUILabel : public GUIWidget
    {
      public:
        GUILabel(PointF position, const std::string &text, FontSizes fontSize = FontSizes::_20,
                 ColorF textColor = Colors::Wheat);
        void UpdateDerived() override;
        void RenderDerived() override;

      private:
        std::string m_text;
        FontSizes m_fontSize;
        ColorF m_textColor{ Colors::Wheat };
        RID m_ridText{};
    };
}