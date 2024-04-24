#pragma once

#include "GUIWindow.h"

namespace zw {
  class GUIMessageBox : public GUIWindow {
   public:
    GUIMessageBox(PointF position, const std::string &message, const std::string &title = "Message",
                  SizeF size = k_defaultSize, GUIAlign alignment = GUIAlign::Center, bool movable = true);

    void Initialize() override;

   private:
    std::string m_message{};

    static constexpr SizeF k_defaultSize = { 0.5f, 0.2f };
  };
}
