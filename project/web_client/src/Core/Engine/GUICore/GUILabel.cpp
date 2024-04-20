#include "GUILabel.h"

namespace zw
{
    GUILabel::GUILabel(PointF position, const std::string &text, FontSizes fontSize, ColorF textColor)
        : GUIWidget(position, { 0.0f, 0.0f }), m_text(text), m_fontSize(fontSize), m_textColor(textColor)
    {
    }

    void GUILabel::UpdateDerived()
    {
    }

    void GUILabel::RenderDerived()
    {
    }
}