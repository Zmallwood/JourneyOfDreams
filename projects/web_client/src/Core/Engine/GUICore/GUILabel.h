#pragma once

#include "Core/Engine/Rendering/TextRendering/FontSizes.h"
#include "GUIWidget.h"

namespace JourneyOfDreams
{
    class GUILabel : public GUIWidget
    {
      public:
        GUILabel(PointF position, const std::string &text, GUIAlign alignment = GUIAlign::TopLeft,
                 FontSizes fontSize = FontSizes::_20, ColorF textColor = Colors::Wheat);

        GUILabel(PointF position, const std::string &text, ColorF textColor);

        void UpdateDerived() override;

        void RenderDerived() override;

        PointF GetAlignedAbsolutePosition() override;

        void SetText(std::shared_ptr<std::string> text)
        {
            m_text = text;
        }

      private:
        std::shared_ptr<std::string> m_text;
        FontSizes m_fontSize;
        ColorF m_textColor{ Colors::Wheat };
        RID m_ridText{};
    };
}
