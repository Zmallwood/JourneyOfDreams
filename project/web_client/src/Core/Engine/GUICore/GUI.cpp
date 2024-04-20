#include "GUI.h"
#include "GUIWidget.h"

namespace zw
{
    void GUI::Update()
    {
        for (auto &entry : m_widgets)
            entry.second->Update();
    }

    void GUI::Render()
    {
        for (auto &entry : m_widgets)
            entry.second->Render();
    }

    void GUI::AddWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> widget) {
        m_widgets.insert({Hash(nameIdentifier), widget});
    }
}