#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "GUI.h"

namespace zw
{
    GUIWidget::GUIWidget(RectF area, GUIAlign alignment)
        : GUIWidget(area.GetPosition(), area.GetSize(), alignment)
    {
    }

    GUIWidget::GUIWidget(PointF position, SizeF size, GUIAlign alignment)
        : m_position(position), m_size(size), m_alignment(alignment)
    {
        m_ridBackgroundImage = _<ImageRenderer>().NewImage();
        m_ridBorderLeft = _<ImageRenderer>().NewImage();
        m_ridBorderRight = _<ImageRenderer>().NewImage();
        m_ridBorderTop = _<ImageRenderer>().NewImage();
        m_ridBorderBottom = _<ImageRenderer>().NewImage();
        m_ridBorderCornerTopLeft = _<ImageRenderer>().NewImage();
        m_ridBorderCornerTopRight = _<ImageRenderer>().NewImage();
        m_ridBorderCornerBottomLeft = _<ImageRenderer>().NewImage();
        m_ridBorderCornerBottomRight = _<ImageRenderer>().NewImage();
    }

    void GUIWidget::Update()
    {
        for (auto &entry : m_childWidgets)
            entry.second->Update();
        UpdateDerived();
    }

    void GUIWidget::Render()
    {
        auto finalPosition = GetFinalPosition();
        auto finalArea = RectF{ finalPosition.x, finalPosition.y, m_size.w, m_size.h };

        if (m_drawBackground)
        {
            auto backgroundPatternFillAmount = SizeF{ .w = finalArea.w * m_backgroundPatternSize.w,
                                                      .h = finalArea.h * m_backgroundPatternSize.h };
            switch (m_alignment)
            {
            case GUIAlign::TopLeft:
                break;
            case GUIAlign::TopCenter:
                finalArea.x -= finalArea.w / 2;
                break;
            case GUIAlign::TopRight:
                finalArea.x -= finalArea.w;
                break;
            case GUIAlign::RightCenter:
                finalArea.x -= finalArea.w;
                finalArea.y -= finalArea.h / 2;
                break;
            case GUIAlign::BottomRight:
                finalArea.x -= finalArea.w;
                finalArea.y -= finalArea.h;
                break;
            case GUIAlign::BottomCenter:
                finalArea.x -= finalArea.w / 2;
                finalArea.y -= finalArea.h;
                break;
            case GUIAlign::BottomLeft:
                finalArea.y -= finalArea.h;
                break;
            case GUIAlign::LeftCenter:
                finalArea.y -= finalArea.h / 2;
                break;
            case GUIAlign::Center:
                finalArea.x -= finalArea.w / 2;
                finalArea.y -= finalArea.h / 2;
                break;
            }
            _<ImageRenderer>().DrawImage(m_ridBackgroundImage, m_backgroundImage, finalArea, true,
                                         backgroundPatternFillAmount);
        }

        if (m_drawBorders)
        {
            auto horizontalBorderWidth = m_borderWidth;
            auto verticalBorderWidth = ConvertWidthToHeight(m_borderWidth);
            auto borderHorizontalPatternFillAmount = SizeF{ 1.0f, finalArea.h * horizontalBorderWidth };
            auto borderVerticalPatternFillAmount = SizeF{ finalArea.w * verticalBorderWidth, 1.0f };

            auto borderLeftalArea = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y,
                                           horizontalBorderWidth, finalArea.h };
            _<ImageRenderer>().DrawImage(m_ridBorderLeft, m_borderVerticalImage, borderLeftalArea, true,
                                         borderHorizontalPatternFillAmount);

            auto borderTopArea
                = RectF{ finalArea.x, finalArea.y - verticalBorderWidth, finalArea.w, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderTop, m_borderHorizontalImage, borderTopArea, true,
                                         borderVerticalPatternFillAmount);

            auto borderRightArea
                = RectF{ finalArea.x + finalArea.w, finalArea.y, horizontalBorderWidth, finalArea.h };
            _<ImageRenderer>().DrawImage(m_ridBorderRight, m_borderVerticalImage, borderRightArea, true,
                                         borderHorizontalPatternFillAmount);

            auto borderBottomArea
                = RectF{ finalArea.x, finalArea.y + finalArea.h, finalArea.w, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderBottom, m_borderHorizontalImage, borderBottomArea, true,
                                         borderVerticalPatternFillAmount);

            auto borderCornerTopLeftArea
                = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y - verticalBorderWidth,
                         horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerTopLeft, m_borderCornerTopLeftImage,
                                         borderCornerTopLeftArea);

            auto borderCornerTopRightArea
                = RectF{ finalArea.x + finalArea.w, finalArea.y - verticalBorderWidth, horizontalBorderWidth,
                         verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerTopRight, m_borderCornerTopRightImage,
                                         borderCornerTopRightArea);

            auto borderCornerBottomRightArea = RectF{ finalArea.x + finalArea.w, finalArea.y + finalArea.h,
                                                      horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomRight, m_borderCornerBottomRightImage,
                                         borderCornerBottomRightArea);

            auto borderCornerBottomLeftArea
                = RectF{ finalArea.x - horizontalBorderWidth, finalArea.y + finalArea.h,
                         horizontalBorderWidth, verticalBorderWidth };
            _<ImageRenderer>().DrawImage(m_ridBorderCornerBottomLeft, m_borderCornerBottomLeftImage,
                                         borderCornerBottomLeftArea);
        }

        // Draw children

        for (auto &entry : m_childWidgets)
            entry.second->Render();

        RenderDerived();
    }

    std::shared_ptr<GUIWidget> GUIWidget::AddWidget(const std::string &nameIdentifier,
                                                    std::shared_ptr<GUIWidget> childWidget)
    {
        childWidget->SetParentWidget(shared_from_this());
        m_childWidgets.insert({ Hash(nameIdentifier), childWidget });

        return childWidget;
    }

    PointF GUIWidget::GetAbsolutePosition()
    {
        auto finalPosition = m_position;
        if (m_parentWidget)
            finalPosition += m_parentWidget->GetAbsolutePosition();
        return finalPosition;
    }

    PointF GUIWidget::GetAlignedAbsolutePosition()
    {
        auto alignedPosition = GetAbsolutePosition();
        if (ParentWidget())
        {
            switch (ParentWidget()->Alignment())
            {
            case GUIAlign::TopLeft:
                break;
            case GUIAlign::TopCenter:
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                break;
            case GUIAlign::TopRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                break;
            case GUIAlign::RightCenter:
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h / 2;
                break;
            case GUIAlign::BottomRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::BottomCenter:
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::BottomLeft:
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::LeftCenter:
                alignedPosition.y -= ParentWidget()->Size().h / 2;
                break;
            case GUIAlign::Center:
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h / 2;
                break;
            }
        }

        return alignedPosition;
    }

    PointF GUIWidget::GetFinalPosition()
    {
        auto paddedAlignedPosition = GetAlignedAbsolutePosition();

        auto horizontalPadding = m_padding;
        auto verticalPadding = ConvertWidthToHeight(m_padding);

        switch (m_alignment)
        {
        case GUIAlign::TopLeft:
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += verticalPadding;
            break;
        case GUIAlign::TopCenter:
            paddedAlignedPosition.y += verticalPadding;
            break;
        case GUIAlign::TopRight:
            paddedAlignedPosition.x -= horizontalPadding;
            paddedAlignedPosition.y += verticalPadding;
            break;
        case GUIAlign::RightCenter:
            paddedAlignedPosition.x -= horizontalPadding;
            break;
        case GUIAlign::BottomRight:
            paddedAlignedPosition.x -= horizontalPadding;
            paddedAlignedPosition.y -= verticalPadding;
            break;
        case GUIAlign::BottomCenter:
            paddedAlignedPosition.y -= verticalPadding;
            break;

        case GUIAlign::BottomLeft:
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y -= verticalPadding;
            break;

        case GUIAlign::LeftCenter:
            paddedAlignedPosition.x += horizontalPadding;
            break;
        case GUIAlign::Center:
            break;
        }

        return paddedAlignedPosition;
    }

    RectF GUIWidget::GetFinalArea()
    {
        auto finalPosition = GetFinalPosition();
        return RectF{ finalPosition.x, finalPosition.y, m_size.w, m_size.h };
    }

    void GUIWidget::Focus()
    {
        GetParentGUI()->SetFocusedWidget(shared_from_this());
        m_ticksTimeGotFocus = Ticks();
    }

    std::shared_ptr<GUI> GUIWidget::GetParentGUI()
    {
        std::shared_ptr<GUIWidget> parent = m_parentWidget;
        while (parent->ParentWidget() != nullptr)
        {
            parent = parent->ParentWidget();
        }
        return dynamic_pointer_cast<GUI>(parent);
    }

    bool GUIWidget::HasFocus()
    {
        return GetParentGUI()->FocusedWidget() == shared_from_this();
    }

    std::map<int, std::shared_ptr<GUIWidget>> GUIWidget::GetChildWidgetsRecursively()
    {
        std::map<int, std::shared_ptr<GUIWidget>> result;
        for (auto &entry : m_childWidgets)
        {
            result.insert(entry);
            auto childResult = entry.second->GetChildWidgetsRecursively();
            result.insert(childResult.begin(), childResult.end());
        }
        return result;
    }
}
