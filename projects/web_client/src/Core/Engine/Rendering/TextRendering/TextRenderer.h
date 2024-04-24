#pragma once

#include "FontSizes.h"

namespace zw
{
    class Font;

    class TextRenderer
    {
      public:
        TextRenderer();

        void RenderText(RID rid, const std::string &text, ColorF color, bool centerAlign, FontSizes fontSize,
                        std::string &outUniqueNameID, SizeF &outSize) const;

        void DrawString(RID rid, const std::string& text, PointF position, ColorF color = Colors::Wheat,
                        bool centerAlign = false, FontSizes fontSize = FontSizes::_30);

        RID NewString();

        SizeF MeasureString(const std::string &text, FontSizes fontSize) const;

        auto Fonts() const
        {
            return m_fonts;
        }

        auto UniqueNameIDs() const
        {
            return m_uniqueNameIDs;
        }

      private:
        const std::string k_relFontsPath = "fonts/";
        const ColorF k_outlineColor = { 0.0f, 0.0f, 0.0f, 1.0f };
        std::map<FontSizes, std::shared_ptr<Font>> m_fonts;
        std::map<RID, std::string> m_uniqueNameIDs;
        std::map<RID, RID> m_ridsGLResources;
    };
}
