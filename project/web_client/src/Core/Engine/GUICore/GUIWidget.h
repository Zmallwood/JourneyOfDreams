#pragma once

#include "GUIAlign.h"

namespace zw
{
    class GUIWidget
    {
      public:
        GUIWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft);
        void Update();
        void Render();
        virtual void UpdateDerived() = 0;
        virtual void RenderDerived() = 0;

      protected:
      private:
        RectF m_area{ 0.0f, 0.0f, 0.0f, 0.0f };
        std::string m_backgroundImage{ "TransparentWood" };
        RID m_ridBackgroundImage{};
        SizeF m_backgroundPatternSize{ 0.2f, 0.2f };
        GUIAlign m_alignment{ GUIAlign::TopLeft };
    };
}