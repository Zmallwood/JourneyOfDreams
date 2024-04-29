#include "GUILabel.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace JourneyOfDreams
{
    GUILabel::GUILabel(PointF position, const std::string &text, GUIAlign alignment, FontSizes fontSize,
                       ColorF textColor)
        : GUIWidget(position, _<TextRenderer>().MeasureString(text, fontSize), alignment),
          m_text(std::make_shared<std::string>(text)), m_fontSize(fontSize), m_textColor(textColor)
    {
        m_ridText = _<TextRenderer>().NewString();
        SetDrawBackground(false);
        SetDrawBorders(false);
    }

    GUILabel::GUILabel(PointF position, const std::string &text, ColorF textColor)
        : GUILabel(position, text, GUIAlign::TopLeft, FontSizes::_20, textColor)
    {
    }

    void GUILabel::UpdateDerived()
    {
    }

    PointF GUILabel::GetAlignedAbsolutePosition()
    {
        auto textSize = _<TextRenderer>().MeasureString(*m_text, m_fontSize);
        auto absolutePosition = GUIWidget::GetAlignedAbsolutePosition();
        PointF alignedPosition;
        switch (Alignment())
        {
        case GUIAlign::TopLeft:
            alignedPosition = absolutePosition;
            break;
        case GUIAlign::TopCenter:
            alignedPosition = PointF(absolutePosition.x - textSize.w / 2, absolutePosition.y);
            break;
        case GUIAlign::TopRight:
            alignedPosition = PointF(absolutePosition.x - textSize.w, absolutePosition.y);
            break;
        case GUIAlign::RightCenter:
            alignedPosition = PointF(absolutePosition.x - textSize.w, absolutePosition.y - textSize.h / 2);
            break;
        case GUIAlign::BottomRight:
            alignedPosition = PointF(absolutePosition.x - textSize.w, absolutePosition.y - textSize.h);
            break;
        case GUIAlign::BottomCenter:
            alignedPosition = PointF(absolutePosition.x - textSize.w / 2, absolutePosition.y - textSize.h);
            break;
        case GUIAlign::BottomLeft:
            alignedPosition = PointF(absolutePosition.x, absolutePosition.y - textSize.h);
            break;
        case GUIAlign::LeftCenter:
            alignedPosition = PointF(absolutePosition.x, absolutePosition.y - textSize.h / 2);
            break;
        case GUIAlign::Center:
            alignedPosition
                = PointF(absolutePosition.x - textSize.w / 2, absolutePosition.y - textSize.h / 2);
            break;
        }
        return alignedPosition;
    }

    void GUILabel::RenderDerived()
    {
        auto finalPosition = GetFinalPosition();
        _<TextRenderer>().DrawString(m_ridText, *m_text, finalPosition, m_textColor, false, m_fontSize);
    }
}
