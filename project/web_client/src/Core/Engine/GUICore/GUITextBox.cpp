#include "GUITextBox.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    GUITextBox::GUITextBox(RectF area, ColorF textColor)
        : GUIWidget(area), m_textColor(textColor), m_cursorHeight(area.h - 2 * Padding())
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridText = _<TextRenderer>().NewString();
        m_ridCursorImage = _<ImageRenderer>().NewImage();

        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultTextBoxBackground");
    }

    void GUITextBox::UpdateDerived()
    {
        auto mousePos = GetMousePosition();

        if (GetFinalArea().Contains(mousePos))
        {
            if (_<MouseInput>().LeftButton().Pressed())
            {
                Focus();
            }
        }
    }

    void GUITextBox::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, BackgroundImage(), GetFinalArea());

        _<TextRenderer>().DrawString(m_ridText, m_text, GetFinalPosition(), m_textColor, false,
                                     FontSizes::_20);

        auto finalPosition = GetFinalPosition();

        auto cursorX = finalPosition.x
                       + _<TextRenderer>().MeasureString(m_text.substr(0, m_cursorPosition), FontSizes::_20).w
                       + Padding();
        auto cursorY = finalPosition.y + Padding();

        bool cursorVisible;

        if (HasFocus() && Ticks() % 1000 < 500)
        {
            cursorVisible = true;
        }
        else
        {
            cursorVisible = false;
        }

        if (cursorVisible)
        {
            _<ImageRenderer>().DrawImage(m_ridCursorImage, k_cursorImage,
                                         RectF{ cursorX, cursorY, k_cursorWidth, m_cursorHeight });
        }
    }
}