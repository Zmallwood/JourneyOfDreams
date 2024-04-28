#include "GUIWindow.h"

namespace zw {
  GUIWindow::GUIWindow(zw::Engine& engine, RectF area, const std::string &title, GUIAlign alignment, bool movable)
      : GUIMovableWidget(engine, area, alignment, movable), m_title(title) {
  }
}