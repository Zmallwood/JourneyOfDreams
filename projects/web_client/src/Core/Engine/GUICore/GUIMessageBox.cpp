/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUIMessageBox.h"
#include "GUIButton.h"
#include "GUILabel.h"

/* GUIMessageBox class implementation. */

namespace JourneyOfDreams
{
  GUIMessageBox::GUIMessageBox(PointF position, const std::string &message,
                               const std::string &title, SizeF size,
                               GUIAlign alignment, bool movable)
      : GUIWindow(RectF{position.x, position.y, size.w, size.h}, title,
                  alignment, movable),
        m_message(message) {
  }

  void GUIMessageBox::Initialize() {
    /* 1) Add a label to this window.
     * 2) Add a confirm button to this window. */
    AddWidget(std::make_shared<GUILabel>(PointF{0.0f, 0.0f}, m_message));
    AddWidget(std::make_shared<GUIButton>(RectF{0.35f, 0.1f, 0.1f, 0.05f}, "OK",
                                          [this]() { Destroy(); }));
  }
}