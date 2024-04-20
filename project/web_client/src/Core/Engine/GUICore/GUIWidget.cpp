#include "GUIWidget.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw
{
    GUIWidget::GUIWidget(RectF area) : m_area(area)
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
        _<ImageRenderer>().DrawImage(m_ridBackgroundImage, m_backgroundImage, m_area, true,
                                     backgroundPatternFillAmount);
        RenderDerived();
    }
}