#include "GUIButton.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    GUIButton::GUIButton(RectF area, const std::string &text, std::function<void()> onClick, ColorF textColor)
        : GUIWidget(area), m_text(text), m_textColor(textColor), m_onClick(std::move(onClick))
    {
        m_ridText = _<TextRenderer>().NewString();
        m_ridBackground = _<ImageRenderer>().NewImage();

        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultButtonBackground");
        SetBackgroundHoveredImage("GUIDefaultButtonBackgroundHovered");
    }

    void GUIButton::UpdateDerived()
    {
        auto mousePos = GetMousePosition();

        if (GetFinalArea().Contains(mousePos))
        {
            m_isHovered = true;

            if (_<MouseInput>().LeftButton().Pressed())
            {
                m_onClick();
            }
        }
        else
        {
            m_isHovered = false;
        }
    }

    void GUIButton::RenderDerived()
    {
        std::string backgroundImage;

        if (m_isHovered)
        {
            backgroundImage = BackgroundHoveredImage();
        }
        else
        {
            backgroundImage = BackgroundImage();
        }

        _<ImageRenderer>().DrawImage(m_ridBackground, backgroundImage, GetFinalArea());

        auto finalPosition = GetFinalPosition();
        auto textPosition
            = PointF{ finalPosition.x + GetFinalArea().w / 2, finalPosition.y + GetFinalArea().h / 2 };
        _<TextRenderer>().DrawString(m_ridText, m_text, textPosition, m_textColor, true, FontSizes::_20);
    }
}