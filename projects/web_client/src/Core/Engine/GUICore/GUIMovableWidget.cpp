// Copyright (c) 2024 Andreas Åkerberg.

#include "GUIMovableWidget.h"

// gui_movable_widget class implementation.

namespace journey_of_dreams
{
  GUIMovableWidget::GUIMovableWidget(RectF area, GUIAlign alignment,
                                     bool movable)
      : GUIWidget(area, alignment), m_movable(movable) {
    /*
    ** Do nothing. */
  }
} // namespace journey_of_dreams