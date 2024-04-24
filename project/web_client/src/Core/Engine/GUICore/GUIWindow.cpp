#include "GUIWindow.h"

namespace zw {
  GUIWindow::GUIWindow(RectF area, const std::string &title, GUIAlign alignment, bool movable)
      : GUIMovableWidget(area, alignment, movable), m_title(title) {
  }
}