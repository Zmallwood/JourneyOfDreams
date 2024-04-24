#include "Font.h"

namespace zw 
{
    Font::Font(const std::string &fontFileName, int fontSize)
    {
        m_font = std::shared_ptr<TTF_Font>(TTF_OpenFont(fontFileName.c_str(), fontSize), SDLDeleter());
        m_outlineFont = std::shared_ptr<TTF_Font>(TTF_OpenFont(fontFileName.c_str(), fontSize), SDLDeleter());

        TTF_SetFontOutline(m_outlineFont.get(), k_fontOutlineWidth);
    }
}