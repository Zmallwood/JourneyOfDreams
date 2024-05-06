// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
typedef struct _TTF_Font TTF_Font;

// font class declaration.

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Represents a font for rendering text.
  /////////////////////////////////////////////////
  class Font {
   public:
    /////////////////////////////////////////////////
    /// Create a regular font object and a font object with an outline.
    ///
    /// \param fontFileName The file name of the font.
    /// \param fontSize The point size of the font.
    /////////////////////////////////////////////////
    Font(const std::string &fontFileName, int fontSize);

    /////////////////////////////////////////////////
    /// Get the regular font object.
    ///
    /// \return The regular font object.
    /////////////////////////////////////////////////
    std::shared_ptr<TTF_Font> SDLFont() const;

    /////////////////////////////////////////////////
    /// Get the font object with an outline.
    ///
    /// \return The font object with an outline.
    /////////////////////////////////////////////////
    std::shared_ptr<TTF_Font> OutlineSDLFont() const;

    /////////////////////////////////////////////////
    /// Get the width of the font outline.
    ///
    /// \return The width of the font outline.
    /////////////////////////////////////////////////
    static const int FontOutlineWidth();

   private:
    std::shared_ptr<TTF_Font> m_font;
    std::shared_ptr<TTF_Font> m_outlineFont;
    static constexpr int k_fontOutlineWidth{2};
  };
} // namespace JourneyOfDreams
