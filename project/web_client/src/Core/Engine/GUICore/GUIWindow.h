#pragma once

#include "GUIMovableWidget.h"

namespace zw
{
    class GUIWindow : public GUIMovableWidget
    {
      public:
        GUIWindow(RectF area, const std::string &title, GUIAlign alignment = GUIAlign::TopLeft,
                  bool movable = true);

      private:
        std::string m_title{};
    };
}