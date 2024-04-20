#include "GUIPanel.h"

namespace zw
{
    void GUIPanel::UpdateDerived()
    {
        for (auto &entry : m_containedWidgets)
            entry.second->Update();
    }

    void GUIPanel::RenderDerived()
    {
        for (auto &entry : m_containedWidgets)
            entry.second->Render();
    }
}