#include "GUILabel.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    GUILabel::GUILabel(PointF position, const std::string &text, FontSizes fontSize, ColorF textColor)
        : GUIWidget(position, _<TextRenderer>().MeasureString(m_text, m_fontSize)), m_text(text),
          m_fontSize(fontSize), m_textColor(textColor)
    {
        m_ridText = _<TextRenderer>().NewString();
    }

    void GUILabel::UpdateDerived()
    {
    }

    void GUILabel::RenderDerived()
    {
        auto alignedPosition = GetFinalPosition();
        if (ParentWidget())
        {
            switch (ParentWidget()->Alignment())
            {
            case GUIAlign::TopLeft:
                break;
            case GUIAlign::TopRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                break;
            case GUIAlign::BottomRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::BottomLeft:
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::Center:
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h / 2;
                break;
            }
        }
        _<TextRenderer>().DrawString(m_ridText, m_text, alignedPosition, m_textColor, false, m_fontSize);
    }
}