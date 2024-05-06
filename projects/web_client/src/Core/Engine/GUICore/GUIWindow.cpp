// Copyright (c) 2024 Andreas Åkerberg.

#include "GUIWindow.h"

// gui_window class implementation.

namespace JourneyOfDreams
{
  GUIWindow::GUIWindow(RectF area, const std::string &title, GUIAlign alignment,
                       bool movable)
      : GUIMovableWidget(area, alignment, movable), m_title(title) {
    /*
    ** Do nothing. */
  }
} // namespace JourneyOfDreams