#pragma once

#include "GUIAlign.h"

namespace zw
{
    class GUIWidget
    {
      public:
        GUIWidget() = default;
        GUIWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft);
        GUIWidget(PointF position, SizeF size, GUIAlign alignment = GUIAlign::TopLeft);
        virtual void Update();
        virtual void Render();
        virtual void UpdateDerived()
        {
        }
        virtual void RenderDerived()
        {
        }
        void AddChildWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> childWidget);
        auto &ChildWidgets()
        {
            return m_childWidgets;
        }

      protected:
      private:
        PointF m_position{ 0.0f, 0.0f };
        SizeF m_size{ 100.0f, 100.0f };
        std::string m_backgroundImage{ "TransparentWood" };
        RID m_ridBackgroundImage{};
        SizeF m_backgroundPatternSize{ 0.2f, 0.2f };
        GUIAlign m_alignment{ GUIAlign::TopLeft };
        std::map<int, std::shared_ptr<GUIWidget>> m_childWidgets;
    };
}