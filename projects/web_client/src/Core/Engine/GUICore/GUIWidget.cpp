#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "GUI.h"

namespace JourneyOfDreams
{
    GUIWidget::GUIWidget(RectF area, GUIAlign alignment)
        : GUIWidget(area.GetPosition(), area.GetSize(), alignment)
    {
    }

    GUIWidget::GUIWidget(PointF position, SizeF size, GUIAlign alignment)
        : m_position(position), m_size(size), m_alignment(alignment),
          m_widgetsToInsert(std::make_shared<std::vector<WidgetEntry>>())
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

    void GUIWidget::InsertWaitingWidgets()
    {
        for (auto &entry : *m_widgetsToInsert)
        {
            m_childWidgets.push_back(entry);
        }
        m_widgetsToInsert->clear();
        for (auto &entry : m_childWidgets)
        {
            entry.widget->InsertWaitingWidgets();
        }
    }

    void GUIWidget::Destroy()
    {
        m_markedForDestruction = true;
        for (auto &entry : m_childWidgets)
            entry.widget->Destroy();
    }

    void GUIWidget::DestroyMarkedWidgets()
    {
        for (auto it = ChildWidgets().begin(); it != ChildWidgets().end();)
        {
            it->widget->DestroyMarkedWidgets();

            if (it->widget->MarkedForDestruction())
            {
                it = ChildWidgets().erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    bool GUIWidget::MouseOver()
    {
        auto mousePosition = GetMousePosition();
        auto finalArea = GetFinalArea();
        std::cout << "mouse x: " << mousePosition.x << ", mouse y: " << mousePosition.y << std::endl;
        std::cout << "finalArea x: " << finalArea.x << ", finalArea y: " << finalArea.y << std::endl;
        std::cout << "finalArea w: " << finalArea.w << ", finalArea h: " << finalArea.h << std::endl;
        return mousePosition.x >= finalArea.x && mousePosition.x <= finalArea.x + finalArea.w
               && mousePosition.y >= finalArea.y && mousePosition.y <= finalArea.y + finalArea.h;
    }

    void GUIWidget::BringToFront()
    {
        if (ParentWidget() == nullptr)
            return;

        auto &parentWidgets = ParentWidget()->ChildWidgets();

        if (parentWidgets.size() == 0)
            return;

        int i;
        for (i = 0; i < parentWidgets.size(); i++)
        {
            if (parentWidgets[i].widget.get() == this)
            {
                break;
            }
        }

        auto it = parentWidgets.begin() + i;
        std::rotate(it, it + 1, parentWidgets.end());
    }

    void GUIWidget::Update()
    {
        if (!m_visible)
            return;
        for (auto &entry : m_childWidgets)
            entry.widget->Update();
        UpdateDerived();
    }

    void GUIWidget::Render()
    {
        if (!m_visible)
            return;
        auto alignedAbsPosition = GetAlignedAbsolutePosition();
        auto finalArea = RectF{ alignedAbsPosition.x, alignedAbsPosition.y, m_size.w, m_size.h };
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
        for (auto &entry : m_childWidgets)
            entry.widget->Render();
        RenderDerived();
    }

    std::shared_ptr<GUIWidget> GUIWidget::AddWidget(const std::string &nameIdentifier,
                                                    std::shared_ptr<GUIWidget> childWidget)
    {
        auto nameHash = Hash(nameIdentifier);
        for (auto &entry : m_childWidgets)
        {
            if (entry.id == nameHash)
            {
                return nullptr;
            }
        }
        for (auto &entry : *m_widgetsToInsert)
        {
            if (entry.id == nameHash)
            {
                return nullptr;
            }
        }
        childWidget->Initialize();
        childWidget->SetParentWidget(shared_from_this());
        m_widgetsToInsert->push_back({ nameHash, childWidget });
        return childWidget;
    }

    std::shared_ptr<GUIWidget> GUIWidget::AddWidget(std::shared_ptr<GUIWidget> childWidget)
    {
        auto generatedName = "Widget" + std::to_string(s_unnamedWidgetCounter++);
        return AddWidget(generatedName, childWidget);
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
            paddedAlignedPosition.x += -m_size.w / 2;
            paddedAlignedPosition.y += verticalPadding;
            break;
        case GUIAlign::TopRight:
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += verticalPadding;
            break;
        case GUIAlign::RightCenter:
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += -m_size.h / 2;
            break;
        case GUIAlign::BottomRight:
            paddedAlignedPosition.x += -m_size.w - horizontalPadding;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;
            break;
        case GUIAlign::BottomCenter:
            paddedAlignedPosition.x += -m_size.w / 2;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;
            break;
        case GUIAlign::BottomLeft:
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += -m_size.h - verticalPadding;
            break;
        case GUIAlign::LeftCenter:
            paddedAlignedPosition.x += horizontalPadding;
            paddedAlignedPosition.y += m_size.h / 2;
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

    std::vector<WidgetEntry> GUIWidget::GetChildWidgetsRecursively()
    {
        std::vector<WidgetEntry> result;
        for (auto &entry : m_childWidgets)
        {
            result.push_back(entry);
            auto childResult = entry.widget->GetChildWidgetsRecursively();
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
        return result;
    }
}
