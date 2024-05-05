// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "FontSizes.h"

namespace journey_of_dreams {
    class Font;

    /////////////////////////////////////////////////
    /// Provides text rendering functionality.
    /////////////////////////////////////////////////
    class TextRenderer {
      public:
        /////////////////////////////////////////////////
        /// Initialize SDL_ttf and load fonts for the
        /// available point sizes.
        /////////////////////////////////////////////////
        TextRenderer();

        /////////////////////////////////////////////////
        /// Draw a string of text to the canvas.
        ///
        /// \param rid The resource ID of the string.
        /// \param text The text to draw.
        /// \param position The position to draw the text.
        /// \param color The color of the text.
        /// \param centerAlign Whether to center-align the text.
        /// \param fontSize The point size of the font.
        /////////////////////////////////////////////////
        void DrawString(RID rid, const std::string &text, PointF position, ColorF color = Colors::Wheat,
                        bool centerAlign = false, FontSizes fontSize = FontSizes::_30);

        /////////////////////////////////////////////////
        /// Allocate resources for a new string of text to be drawn.
        ///
        /// \return The resource ID of the string.
        /////////////////////////////////////////////////
        RID NewString();

        /////////////////////////////////////////////////
        /// Measure the size of a rendered string of text.
        ///
        /// \param text The text to measure.
        /// \param fontSize The point size of the font to
        ///                 use for measuring the text.
        /// \return The size (in the canvas) of the text.
        /////////////////////////////////////////////////
        SizeF MeasureString(const std::string &text, FontSizes fontSize) const;

      private:
        void RenderText(RID rid, const std::string &text, ColorF color, bool centerAlign, FontSizes fontSize,
                        std::string &outUniqueNameID, SizeF &outSize) const;
        const std::string k_relFontsPath = "fonts/";
        const ColorF k_outlineColor = { 0.0f, 0.0f, 0.0f, 1.0f };
        std::map<FontSizes, std::shared_ptr<Font>> m_fonts;
        std::map<RID, std::string> m_uniqueNameIDs;
        std::map<RID, RID> m_ridsGLResources;
    };
}
