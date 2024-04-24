#include "GUIMovableWidget.h"

namespace zw {
  GUIMovableWidget::GUIMovableWidget(RectF area, GUIAlign alignment, bool movable)
      : GUIWidget(area, alignment), m_movable(movable) {
  }
}