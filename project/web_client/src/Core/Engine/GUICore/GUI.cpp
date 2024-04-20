#include "GUI.h"
#include "GUIWidget.h"

namespace zw
{
    void GUI::Update()
    {
        for (auto &entry : ChildWidgets())
            entry.second->Update();
    }

    void GUI::Render()
    {
        for (auto &entry : ChildWidgets())
            entry.second->Render();
    }

    void GUI::AddWidget(const std::string &nameIdentifier, std::shared_ptr<GUIWidget> widget)
    {
        ChildWidgets().insert({ Hash(nameIdentifier), widget });
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget (const std::string &nameIdentifier,
                                              std::shared_ptr<GUIWidget> widget)
    {
        for (auto &entry : ChildWidgets())
        {
            if (entry.first == Hash(nameIdentifier))
            {
                return entry.second;
            }
        }

        for (auto &entry : ChildWidgets())
        {
            auto result = GetWidget(nameIdentifier, entry.second);
            if (result)
            {
                return result;
            }
        }

        return nullptr;
    }

}