/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Font.h"

/* Font class implementation. */

namespace JourneyOfDreams
{
  Font::Font(const std::string &fontFileName, int fontSize) {
    m_font = std::shared_ptr<TTF_Font>(
        TTF_OpenFont(fontFileName.c_str(), fontSize), SDLDeleter());
    m_outlineFont = std::shared_ptr<TTF_Font>(
        TTF_OpenFont(fontFileName.c_str(), fontSize), SDLDeleter());

    TTF_SetFontOutline(m_outlineFont.get(), k_fontOutlineWidth);
  }

  std::shared_ptr<TTF_Font> Font::SDLFont() const {
    return m_font;
  }

  std::shared_ptr<TTF_Font> Font::OutlineSDLFont() const {
    return m_outlineFont;
  }

  const int Font::FontOutlineWidth() {
    return k_fontOutlineWidth;
  }
}