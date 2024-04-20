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
        auto finalPosition = GetFinalPosition();
        _<TextRenderer>().DrawString(m_ridText, m_text, finalPosition, m_textColor, false, m_fontSize);
    }
}