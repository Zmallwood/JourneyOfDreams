#pragma once

#include "GUIWidget.h"

namespace zw
{
    class GUIButton : public GUIWidget
    {
      public:
        GUIButton(RectF area, const std::string &text, std::function<void()> onClick,
                  ColorF textColor = Colors::Wheat);
        void UpdateDerived() override;
        void RenderDerived() override;

      protected:
        auto BackgroundHoveredImage()
        {
            return m_backgroundHoveredImage;
        }
        void SetBackgroundHoveredImage(const std::string &backgroundHoveredImage)
        {
            m_backgroundHoveredImage = backgroundHoveredImage;
        }

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