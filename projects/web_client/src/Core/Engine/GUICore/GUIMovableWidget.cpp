#include "GUIMovableWidget.h"

namespace JourneyOfDreams
{
    GUIMovableWidget::GUIMovableWidget(RectF area, GUIAlign alignment, bool movable)
        : GUIWidget(area, alignment), m_movable(movable)
    {
    }
}