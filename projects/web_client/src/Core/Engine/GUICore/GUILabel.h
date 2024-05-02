//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

#include "Core/Engine/Rendering/TextRendering/FontSizes.h"
#include "GUIWidget.h"

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// A label widget for the GUI.
    /////////////////////////////////////////////////
    class GUILabel : public GUIWidget
    {
      public:
        /////////////////////////////////////////////////
        /// Initialize class members and graphical resources
        /// and setup the default appearance of the label.
        ///
        /// \param position Position of the label.
        /// \param text Text to display on the label.
        /// \param alignment Alignment of the label.
        /// \param fontSize Font size of the text.
        /// \param textColor Color of the text.
        /////////////////////////////////////////////////
        GUILabel(PointF position, const std::string &text, GUIAlign alignment = GUIAlign::TopLeft,
                 FontSizes fontSize = FontSizes::_20, ColorF textColor = Colors::Wheat);

        /////////////////////////////////////////////////
        /// Calls the other constructor some default values.
        ///
        /// \param position Position of the label.
        /// \param text Text to display on the label.
        /// \param textColor Color of the text.
        /////////////////////////////////////////////////
        GUILabel(PointF position, const std::string &text, ColorF textColor);

        /////////////////////////////////////////////////
        /// Update the label's state.
        /////////////////////////////////////////////////
        void UpdateDerived() override;

        /////////////////////////////////////////////////
        /// Render the label.
        /////////////////////////////////////////////////
        void RenderDerived() override;

        /////////////////////////////////////////////////
        /// Get absolute position of the label with 
        /// alignement taken into account.
        ///
        /// \return Absolute position of the label.
        /////////////////////////////////////////////////
        PointF GetAlignedAbsolutePosition() override;

        /////////////////////////////////////////////////
        /// Set the text of the label.
        ///
        /// \param text Text to set.
        /////////////////////////////////////////////////
        void SetText(std::shared_ptr<std::string> text);

      private:
        std::shared_ptr<std::string> m_text;
        FontSizes m_fontSize;
        ColorF m_textColor{ Colors::Wheat };
        RID m_ridText{};
    };
}
