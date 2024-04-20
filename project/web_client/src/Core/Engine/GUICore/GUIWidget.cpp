#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw
{
    GUIWidget::GUIWidget(RectF area, GUIAlign alignment) : m_area(area), m_alignment(alignment)
    {
        m_ridBackgroundImage = _<ImageRenderer>().NewImage();
    }

    void GUIWidget::Update()
    {
        UpdateDerived();
    }

    void GUIWidget::Render()
    {
        auto backgroundPatternFillAmount
            = SizeF{ .w = m_area.w * m_backgroundPatternSize.w, .h = m_area.h * m_backgroundPatternSize.h };
        auto finalArea = m_area;
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
        RenderDerived();
    }
}