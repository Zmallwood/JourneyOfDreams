#pragma once

#include "GUIWidget.h"

namespace zw {
  class GUIMovableWidget : public GUIWidget {
   public:
    GUIMovableWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft, bool movable = true);

   private:
    bool m_movable{ true };
  };
}