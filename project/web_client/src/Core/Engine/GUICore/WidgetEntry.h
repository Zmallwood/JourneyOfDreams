#pragma once

namespace zw
{
    class GUIWidget;

    class WidgetEntry
    {
      public:
        int id {0};
        std::shared_ptr<GUIWidget> widget {};
    };
}