// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIMovableWidget.h"

namespace JourneyOfDreams {
    /////////////////////////////////////////////////
    /// Window widget that can be moved around.
    /////////////////////////////////////////////////
    class GUIWindow : public GUIMovableWidget {
      public:
        /////////////////////////////////////////////////
        /// Forwards the constructor to the base class
        /// and sets the title of the window.
        ///
        /// \param area The area of the window.
        /// \param title The title of the window.
        /// \param alignment The alignment of the window.
        /// \param movable Whether the window is movable.
        /////////////////////////////////////////////////
        GUIWindow(RectF area, const std::string &title, GUIAlign alignment = GUIAlign::TopLeft,
                  bool movable = true);

      private:
        std::string m_title{};
    };
}