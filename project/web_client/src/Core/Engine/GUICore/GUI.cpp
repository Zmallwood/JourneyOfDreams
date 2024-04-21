#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "GUIWidget.h"

namespace zw
{
    void GUI::Update()
    {
        for (auto &entry : ChildWidgets())
            entry.second->Update();

        if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        {
            FocusNextWidget();
        }
    }

    void GUI::Render()
    {
        for (auto &entry : ChildWidgets())
            entry.second->Render();
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier,
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

    void GUI::FocusNextWidget()
    {
        if (ChildWidgets().empty())
        {
            return;
        }

        std::shared_ptr<GUIWidget> widget = FocusedWidget();

        for (auto &entry : GetChildWidgetsRecursively())
        {
            if (widget == nullptr && entry.second->Focusable())
            {
                widget = entry.second;
                break;
            }
            else if (widget != nullptr && entry.second->Focusable() && widget != entry.second)
            {
                widget = entry.second;
                break;
            }
        }

        SetFocusedWidget(widget);
    }
}