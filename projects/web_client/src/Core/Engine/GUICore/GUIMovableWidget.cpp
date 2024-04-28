#include "GUIMovableWidget.h"

namespace zw {
  GUIMovableWidget::GUIMovableWidget(zw::Engine& engine, RectF area, GUIAlign alignment, bool movable)
      : GUIWidget(engine, area, alignment), m_movable(movable) {
  }
}