#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

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
    }

    void GUIWidget::Update()
    {
        for (auto &entry : m_childWidgets)
            entry.second->Update();
        UpdateDerived();
    }

    void GUIWidget::Render()
    {
        auto finalPosition = GetAbsolutePosition();
        auto finalArea = RectF{ finalPosition.x, finalPosition.y, m_size.w, m_size.h };
        auto backgroundPatternFillAmount = SizeF{ .w = finalArea.w * m_backgroundPatternSize.w,
                                                  .h = finalArea.h * m_backgroundPatternSize.h };
        switch (m_alignment)
        {
        case GUIAlign::TopLeft:
            break;
        case GUIAlign::TopRight:
            finalArea.x -= finalArea.w;
            break;
        case GUIAlign::BottomRight:
            finalArea.x -= finalArea.w;
            finalArea.y -= finalArea.h;
            break;
        case GUIAlign::BottomLeft:
            finalArea.y -= finalArea.h;
            break;
        case GUIAlign::Center:
            finalArea.x -= finalArea.w / 2;
            finalArea.y -= finalArea.h / 2;
            break;
        }
        _<ImageRenderer>().DrawImage(m_ridBackgroundImage, m_backgroundImage, finalArea, true,
                                     backgroundPatternFillAmount);

        for (auto &entry : m_childWidgets)
            entry.second->Render();

        RenderDerived();
    }

    void GUIWidget::AddWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> childWidget)
    {
        childWidget->SetParentWidget(shared_from_this());
        m_childWidgets.insert({ Hash(nameIdentifier), childWidget });
    }

    PointF GUIWidget::GetAbsolutePosition()
    {
        auto finalPosition = m_position;
        if (m_parentWidget)
            finalPosition += m_parentWidget->GetAbsolutePosition();
        return finalPosition;
    }

    PointF GUIWidget::GetFinalPosition()
    {
        auto alignedPosition = GetAbsolutePosition();
        if (ParentWidget())
        {
            switch (ParentWidget()->Alignment())
            {
            case GUIAlign::TopLeft:
                break;
            case GUIAlign::TopRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                break;
            case GUIAlign::BottomRight:
                alignedPosition.x -= ParentWidget()->Size().w;
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::BottomLeft:
                alignedPosition.y -= ParentWidget()->Size().h;
                break;
            case GUIAlign::Center:
                alignedPosition.x -= ParentWidget()->Size().w / 2;
                alignedPosition.y -= ParentWidget()->Size().h / 2;
                break;
            }
        }

        auto paddedAlignedPosition = alignedPosition;

        switch (m_alignment)
        {
        case GUIAlign::TopLeft:
            paddedAlignedPosition.x += m_padding;
            paddedAlignedPosition.y += m_padding;
            break;
        case GUIAlign::TopRight:
            paddedAlignedPosition.x -= m_padding;
            paddedAlignedPosition.y += m_padding;
            break;
        case GUIAlign::BottomRight:
            paddedAlignedPosition.x -= m_padding;
            paddedAlignedPosition.y -= m_padding;
            break;
        case GUIAlign::BottomLeft:
            paddedAlignedPosition.x += m_padding;
            paddedAlignedPosition.y -= m_padding;
            break;
        case GUIAlign::Center:
            break;
        }

        return paddedAlignedPosition;
    }
}