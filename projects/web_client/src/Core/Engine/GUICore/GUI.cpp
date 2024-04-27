#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
// #include "GUIWidget.h"
// #include "OnScreenKeyboard.h"

namespace zw
{
    void GUI::Initialize()
    {
        // AddWidget("OnScreenKeyboard", std::make_shared<OnScreenKeyboard>());
    }

    void GUI::ShowKeyboard()
    {
        // GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Show();
    }

    void GUI::HideKeyboard()
    {
        // GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
    }

    void GUI::Update()
    {
        // GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->BringToFront();

        // if (_<MouseInput>().LeftButton().Pressed()
        //     && !GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->MouseOver())
        // {
        //     SetFocusedWidget(nullptr);
        // }

        // // Update all child widgets in the same order as they have been added.
        // for (auto &entry : ChildWidgets())
        //     entry.widget->Update();

        // // Destroy all widgets that should be destroyed.
        // DestroyMarkedWidgets();

        // // Insert new widgets that are waiting to be inserted.
        // InsertWaitingWidgets();

        // // Focus next widget on pressing the tab key.
        // if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        // {
        //     FocusNextWidget();
        // }

        // // Clear all typed text input as it has already been handled by the GUIs widgets.
        // _<KeyboardInput>().ClearTextInput();

        // if (FocusedWidget() == nullptr)
        // {
        //     GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
        // }
    }

    void GUI::Render()
    {
        // // Render all widgets in the same order as they have been added.
        // for (auto &entry : ChildWidgets())
        //     entry.widget->Render();
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier)
    {
        // // Search in all widgets recursively for the widget with the specified name.
        // for (auto &entry : GetChildWidgetsRecursively())
        // {
        //     // If widget name hash is found.
        //     if (entry.id == Hash(nameIdentifier))
        //     {
        //         // Return the widget.
        //         return entry.widget;
        //     }
        // }

        // // Widget with the specified name not found.
        return nullptr;
    }

    void GUI::FocusNextWidget()
    {
        // if (ChildWidgets().empty())
        // // No widgets exist to focus.
        // {
        //     return;
        // }

        // // Get currently focused widget.
        // auto widget = FocusedWidget();

        // // Search through all widgets recursively for the next widget to focus.
        // for (auto &entry : GetChildWidgetsRecursively())
        // {
        //     if (widget == nullptr && entry.widget->Focusable())
        //     // If no widget is currently focused, return first focusable widget.
        //     {
        //         widget = entry.widget;

        //         break;
        //     }
        //     else if (widget != nullptr && entry.widget->Focusable() && widget != entry.widget)
        //     // If a widget is currently focused, return the first focusable widget
        //     // which does not equal to the currently focused.
        //     {
        //         widget = entry.widget;

        //         break;
        //     }
        // }

        // // Focus the selected widget.
        // SetFocusedWidget(widget);
    }
}
