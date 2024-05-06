// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIWidget.h"

// gui_movable_widget class declaration.

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// A movable widget for the GUI.
  /////////////////////////////////////////////////
  class GUIMovableWidget : public GUIWidget {
   public:
    /////////////////////////////////////////////////
    /// Forwards the constructor arguments to the base
    /// class and initializes the movable flag.
    ///
    /// \param area Area of the widget.
    /// \param alignment Alignment of the widget.
    /// \param movable Whether the widget is movable.
    /////////////////////////////////////////////////
    GUIMovableWidget(RectF area, GUIAlign alignment = GUIAlign::TopLeft,
                     bool movable = true);

   private:
    bool m_movable{true};
  };
} // namespace JourneyOfDreams