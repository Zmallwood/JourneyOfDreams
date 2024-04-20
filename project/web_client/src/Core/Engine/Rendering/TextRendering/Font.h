#pragma once

typedef struct _TTF_Font TTF_Font;
namespace zw
{

    class Font
    {
      public:
        Font(const std::string& fontFileName, int fontSize);
        auto SDLFont() const
        {
            return m_font;
        }
        auto OutlineSDLFont() const
        {
            return m_outlineFont;
        }

        static constexpr int k_fontOutlineWidth = 2;

      private:
        std::shared_ptr<TTF_Font> m_font;
        std::shared_ptr<TTF_Font> m_outlineFont;
    };

}