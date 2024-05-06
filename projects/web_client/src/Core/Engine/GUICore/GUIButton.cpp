/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUIButton.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

/* GUIButton class implementation. */

namespace JourneyOfDreams
{
  GUIButton::GUIButton(RectF area, const std::string &text,
                       std::function<void()> onClick, ColorF textColor)
      : GUIWidget(area), m_text(text), m_textColor(textColor),
        m_onClick(std::move(onClick)) {
    /* 1) Allocate graphics resources.
     * 2) Set default properties. */
    m_ridText = _<TextRenderer>().NewString();
    m_ridBackground = _<ImageRenderer>().NewImage();
    SetDrawBackground(false);
    SetDrawBorders(false);
    SetBackgroundImage("GUIDefaultButtonBackground");
    SetBackgroundHoveredImage("GUIDefaultButtonBackgroundHovered");
  }

  void GUIButton::UpdateDerived() {
    /* 1) If mouse is over button area,
     *    then mark as hovered.
     * 2) If mouse button also has been pressed,
     *    then execute button action.
     * 3) Else, mark as not being hovered. */
    auto mousePos = GetMousePosition();
    if (GetFinalArea().Contains(mousePos)) {
      m_isHovered = true;
      if (_<MouseInput>().LeftButton().PressedPickResult()) {
        m_onClick();
      }
    } else {
      m_isHovered = false;
    }
  }

  void GUIButton::RenderDerived() {
    std::string backgroundImage;
    /* 1) Set rendered background image depending
     *    if the button is hovered or not.
     * 2) Draw button background.
     * 3) Determine text draw position.
     * 4) Draw button text. */
    if (m_isHovered) {
      backgroundImage = BackgroundHoveredImage();
    } else {
      backgroundImage = BackgroundImage();
    }
    _<ImageRenderer>().DrawImage(m_ridBackground, backgroundImage,
                                 GetFinalArea());
    auto finalPosition = GetFinalPosition();
    auto textPosition = PointF{finalPosition.x + GetFinalArea().w / 2,
                               finalPosition.y + GetFinalArea().h / 2};
    _<TextRenderer>().DrawString(m_ridText, m_text, textPosition, m_textColor,
                                 true, FontSizes::_20);
  }

  std::string GUIButton::BackgroundHoveredImage() {
    return m_backgroundHoveredImage;
  }

  void GUIButton::SetBackgroundHoveredImage(
      const std::string &backgroundHoveredImage) {
    m_backgroundHoveredImage = backgroundHoveredImage;
  }
}