#pragma once
#include "GUIAlign.h"
#include "WidgetEntry.h"

namespace zw
{
    class GUI;

    class GUIWidget : public std::enable_shared_from_this<GUIWidget>
    {
      public:
        GUIWidget() = default;

        GUIWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft);

        GUIWidget(PointF position, SizeF size, GUIAlign alignment = GUIAlign::TopLeft);

        void InsertWaitingWidgets();

        void Destroy();

        void DestroyMarkedWidgets();

        void BringToFront();

        bool MouseOver();

        virtual void Initialize()
        {
        }

        virtual void Update();

        virtual void Render();

        virtual void UpdateDerived()
        {
        }

        virtual void RenderDerived()
        {
        }

        std::vector<WidgetEntry> GetChildWidgetsRecursively();

        std::shared_ptr<GUIWidget> AddWidget(const std::string &nameIdentifier,
                                             std::shared_ptr<GUIWidget> childWidget);

        std::shared_ptr<GUIWidget> AddWidget(std::shared_ptr<GUIWidget> childWidget);

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

        auto Focusable()
        {
            return m_focusable;
        }

        auto MarkedForDestruction()
        {
            return m_markedForDestruction;
        }

        void SetDrawBackground(bool drawBackground)
        {
            m_drawBackground = drawBackground;
        }

        void SetDrawBorders(bool drawBorders)
        {
            m_drawBorders = drawBorders;
        }

      protected:
        PointF GetFinalPosition();

        RectF GetFinalArea();

        virtual void Focus();

        bool HasFocus();

        virtual PointF GetAlignedAbsolutePosition();

        std::shared_ptr<GUI> GetParentGUI();

        auto BackgroundImage()
        {
            return m_backgroundImage;
        }

        void SetBackgroundImage(const std::string &backgroundImage)
        {
            m_backgroundImage = backgroundImage;
        }

        void SetFocusable(bool focusable)
        {
            m_focusable = focusable;
        }

        auto TicksTimeGotFocus()
        {
            return m_ticksTimeGotFocus;
        }

        void SetVisible(bool visible)
        {
            m_visible = visible;
        }

        void SetPadding(float padding)
        {
            m_padding = padding;
        }

      private:
        PointF GetAbsolutePosition();

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
        std::vector<WidgetEntry> m_childWidgets;
        std::shared_ptr<GUIWidget> m_parentWidget{};
        float m_padding{ 0.01f };
        float m_borderWidth{ 0.01f };
        bool m_drawBackground{ true };
        bool m_drawBorders{ true };
        bool m_focusable{ false };
        int m_ticksTimeGotFocus{ 0 };
        bool m_markedForDestruction{ false };
        std::vector<WidgetEntry> m_widgetsToInsert{};
        bool m_visible{ true };

        inline static int s_unnamedWidgetCounter{ 0 };
    };
}
