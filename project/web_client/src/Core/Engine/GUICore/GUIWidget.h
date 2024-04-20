#pragma once

#include "GUIAlign.h"

namespace zw
{
    class GUIWidget : public std::enable_shared_from_this<GUIWidget>
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
        void AddWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> childWidget);
        auto &ChildWidgets()
        {
            return m_childWidgets;
        }
        auto ParentWidget()
        {
            return m_parentWidget;
        }
        auto SetParentWidget(std::shared_ptr<GUIWidget> parentWidget)
        {
            m_parentWidget = parentWidget;
        }
        auto Alignment()
        {
            return m_alignment;
        }
        void SetSize(SizeF size)
        {
            m_size = size;
        }
        auto Size()
        {
            return m_size;
        }

      protected:
        PointF GetFinalPosition();

      private:
        PointF GetAbsolutePosition();
        
        PointF m_position{ 0.0f, 0.0f };
        SizeF m_size{ 100.0f, 100.0f };
        std::string m_backgroundImage{ "TransparentWood" };
        RID m_ridBackgroundImage{};
        SizeF m_backgroundPatternSize{ 0.2f, 0.2f };
        GUIAlign m_alignment{ GUIAlign::TopLeft };
        std::map<int, std::shared_ptr<GUIWidget>> m_childWidgets;
        std::shared_ptr<GUIWidget> m_parentWidget{};
    };
}