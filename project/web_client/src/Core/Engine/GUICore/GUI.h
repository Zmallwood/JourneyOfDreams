#pragma once

namespace zw
{
    class GUIWidget;

    class GUI
    {
      public:
        void Update();
        void Render();
        void AddWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> widget);

      private:
        std::map<int, std::shared_ptr<GUIWidget>> m_widgets;
    };
}