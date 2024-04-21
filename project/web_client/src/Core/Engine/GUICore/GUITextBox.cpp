#include "GUITextBox.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    GUITextBox::GUITextBox(RectF area, ColorF textColor) : GUIWidget(area), m_textColor(textColor)
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridText = _<TextRenderer>().NewString();

        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultTextBoxBackground");
    }

    void GUITextBox::UpdateDerived()
    {
    }

    void GUITextBox::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, BackgroundImage(), GetFinalArea());
    }
}