#include "GUIButton.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace JourneyOfDreams
{
    GUIButton::GUIButton(RectF area, const std::string &text, std::function<void()> onClick, ColorF textColor)
        : GUIWidget(area), m_text(text), m_textColor(textColor), m_onClick(std::move(onClick))
    {
        /*
        ** Allocate graphics resources. */
        m_ridText = _<TextRenderer>().NewString();
        m_ridBackground = _<ImageRenderer>().NewImage();

        /*
        ** Set default widget properties. */
        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultButtonBackground");
        SetBackgroundHoveredImage("GUIDefaultButtonBackgroundHovered");
    }

    void GUIButton::UpdateDerived()
    {
        auto mousePos = GetMousePosition();

        /*
        ** If mouse is over button area. */
        if (GetFinalArea().Contains(mousePos))
        {
            /*
            ** Mark as hovered. */
            m_isHovered = true;

            /*
            ** If mouse button also has been pressed. */
            if (_<MouseInput>().LeftButton().PressedPickResult())
            {
                /*
                ** Execute button action. */
                m_onClick();
            }
        }
        else
        {
            /*
            ** Mark as not being hovered. */
            m_isHovered = false;
        }
    }

    void GUIButton::RenderDerived()
    {
        std::string backgroundImage;

        /*
        ** Set rendered background image depending if the button is hovered or not. */
        if (m_isHovered)
        {
            backgroundImage = BackgroundHoveredImage();
        }
        else
        {
            backgroundImage = BackgroundImage();
        }

        /*
        ** Draw button background. */
        _<ImageRenderer>().DrawImage(m_ridBackground, backgroundImage, GetFinalArea());

        /*
        ** Determine text draw position. */
        auto finalPosition = GetFinalPosition();
        auto textPosition
            = PointF{ finalPosition.x + GetFinalArea().w / 2, finalPosition.y + GetFinalArea().h / 2 };

        /*
        ** Draw button text. */
        _<TextRenderer>().DrawString(m_ridText, m_text, textPosition, m_textColor, true, FontSizes::_20);
    }

    std::string GUIButton::BackgroundHoveredImage()
    {
        /*
        ** Getter */
        return m_backgroundHoveredImage;
    }

    void GUIButton::SetBackgroundHoveredImage(const std::string &backgroundHoveredImage)
    {
        /*
        ** Setter */
        m_backgroundHoveredImage = backgroundHoveredImage;
    }
}