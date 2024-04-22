#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "GUIWidget.h"

namespace zw
{
    void GUI::Update()
    {
        for (auto &entry : ChildWidgets())
            entry.second->Update();

        DestroyMarkedWidgets();

        if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        {
            FocusNextWidget();
        }

        _<KeyboardInput>().ClearTextInput();
    }

    void GUI::DestroyMarkedWidgets() {
        for (auto it = ChildWidgets().begin(); it != ChildWidgets().end();)
        {
            if (it->second->MarkedForDestruction())
            {
                it = ChildWidgets().erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void GUI::Render()
    {
        for (auto &entry : std::views::reverse(ChildWidgets()))
            entry.second->Render();
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier,
                                              std::shared_ptr<GUIWidget> widget)
    {
        for (auto &entry : GetChildWidgetsRecursively())
        {
            if (entry.first == Hash(nameIdentifier))
            {
                return entry.second;
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