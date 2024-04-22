#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "GUIWidget.h"

namespace zw
{
    void GUI::Update()
    {
        for (auto &entry : ChildWidgets())
            entry.widget->Update();

        DestroyMarkedWidgets();
        InsertWaitingWidgets();

        if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        {
            FocusNextWidget();
        }

        _<KeyboardInput>().ClearTextInput();
    }

    void GUI::DestroyMarkedWidgets()
    {
        for (auto it = ChildWidgets().begin(); it != ChildWidgets().end();)
        {
            if (it->widget->MarkedForDestruction())
                it = ChildWidgets().erase(it);
            else
                ++it;
        }
    }

    void GUI::Render()
    {
        for (auto &entry : ChildWidgets())
            entry.widget->Render();
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier,
                                              std::shared_ptr<GUIWidget> widget)
    {
        for (auto &entry : GetChildWidgetsRecursively())
        {
            if (entry.id == Hash(nameIdentifier))
            {
                return entry.widget;
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
            if (widget == nullptr && entry.widget->Focusable())
            {
                widget = entry.widget;
                break;
            }
            else if (widget != nullptr && entry.widget->Focusable() && widget != entry.widget)
            {
                widget = entry.widget;
                break;
            }
        }

        SetFocusedWidget(widget);
    }
}