#pragma once

#include "GUIWidget.h"

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// A button widget for the GUI.
    /////////////////////////////////////////////////
    class GUIButton : public GUIWidget
    {
      public:
        /////////////////////////////////////////////////
        /// Initialize class members and graphical resources
        /// and setup the default appearance of the button.
        ///
        /// \param area Area of the button.
        /// \param text Text to display on the button.
        /// \param onClick Function to call when the button is clicked.
        /// \param textColor Color of the text.
        /////////////////////////////////////////////////
        GUIButton(RectF area, const std::string &text, std::function<void()> onClick,
                  ColorF textColor = Colors::Wheat);

        /////////////////////////////////////////////////
        /// Update the button's state.
        /////////////////////////////////////////////////
        void UpdateDerived() override;

        /////////////////////////////////////////////////
        /// Render the button.
        /////////////////////////////////////////////////
        void RenderDerived() override;

      protected:
        /////////////////////////////////////////////////
        /// Get the background image for the button when hovered.
        ///
        /// \return Background image for the button when hovered.
        /////////////////////////////////////////////////
        std::string BackgroundHoveredImage();

        /////////////////////////////////////////////////
        /// Set the background image for the button when
        /// hovered.
        ///
        /// \param backgroundHoveredImage Background image for
        ///                               the button when hovered.
        /////////////////////////////////////////////////
        void SetBackgroundHoveredImage(const std::string &backgroundHoveredImage);

      private:
        RID m_ridText{};
        std::string m_text;
        ColorF m_textColor{ Colors::Wheat };
        std::function<void()> m_onClick;
        RID m_ridBackground{};
        bool m_isHovered{ false };
        std::string m_backgroundHoveredImage{};
    };
}
