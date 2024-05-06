/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUIMovableWidget.h"

/* GUIMovableWidget class implementation. */

namespace JourneyOfDreams
{
  GUIMovableWidget::GUIMovableWidget(RectF area, GUIAlign alignment,
                                     bool movable)
      : GUIWidget(area, alignment), m_movable(movable) {
  }
}