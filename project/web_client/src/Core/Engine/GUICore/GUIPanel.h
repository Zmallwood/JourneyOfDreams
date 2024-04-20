#pragma once

#include "GUIWidget.h"

namespace zw
{
    class GUIPanel : public GUIWidget
    {
      public:
        using GUIWidget::GUIWidget;
        void UpdateDerived() override;
        void RenderDerived() override;

      private:
        std::map<int, std::shared_ptr<GUIWidget>> m_containedWidgets;
    };
}