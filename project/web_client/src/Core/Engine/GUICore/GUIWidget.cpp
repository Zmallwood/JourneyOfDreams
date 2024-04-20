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
        auto finalArea = RectF{ m_position.x, m_position.y, m_size.w, m_size.h };
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

    void GUIWidget::AddChildWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> childWidget)
    {
        m_childWidgets.insert({ Hash(nameIdentifier), childWidget });
    }
}