#pragma once

#include "GUIAlign.h"

namespace zw
{
    class GUI;

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
        std::shared_ptr<GUIWidget> AddWidget(const std::string &nameIdentifier,
                                             std::shared_ptr<GUIWidget> childWidget);
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
        auto Padding()
        {
            return m_padding;
        }

      protected:
        PointF GetFinalPosition();
        RectF GetFinalArea();
        void Focus();
        bool HasFocus();
        void SetDrawBackground(bool drawBackground)
        {
            m_drawBackground = drawBackground;
        }
        void SetDrawBorders(bool drawBorders)
        {
            m_drawBorders = drawBorders;
        }
        auto BackgroundImage()
        {
            return m_backgroundImage;
        }
        void SetBackgroundImage(const std::string &backgroundImage)
        {
            m_backgroundImage = backgroundImage;
        }

      private:
        PointF GetAbsolutePosition();
        std::shared_ptr<GUI> GetParentGUI();

        PointF m_position{ 0.0f, 0.0f };
        SizeF m_size{ 100.0f, 100.0f };
        std::string m_backgroundImage{ "GUIDefaultBackground" };
        std::string m_borderVerticalImage{ "GUIDefaultBorderVertical" };
        std::string m_borderHorizontalImage{ "GUIDefaultBorderHorizontal" };
        std::string m_borderCornerTopLeftImage{ "GUIDefaultBorderCornerTopLeft" };
        std::string m_borderCornerTopRightImage{ "GUIDefaultBorderCornerTopRight" };
        std::string m_borderCornerBottomRightImage{ "GUIDefaultBorderCornerBottomRight" };
        std::string m_borderCornerBottomLeftImage{ "GUIDefaultBorderCornerBottomLeft" };
        RID m_ridBackgroundImage{};
        RID m_ridBorderLeft;
        RID m_ridBorderTop;
        RID m_ridBorderRight;
        RID m_ridBorderBottom;
        RID m_ridBorderCornerTopLeft;
        RID m_ridBorderCornerTopRight;
        RID m_ridBorderCornerBottomRight;
        RID m_ridBorderCornerBottomLeft;
        SizeF m_backgroundPatternSize{ 0.2f, 0.2f };
        GUIAlign m_alignment{ GUIAlign::TopLeft };
        std::map<int, std::shared_ptr<GUIWidget>> m_childWidgets;
        std::shared_ptr<GUIWidget> m_parentWidget{};
        float m_padding{ 0.01f };
        float m_borderWidth{ 0.01f };
        bool m_drawBackground{ true };
        bool m_drawBorders{ true };
    };
}