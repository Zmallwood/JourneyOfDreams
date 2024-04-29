#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "GUIWidget.h"
#include "OnScreenKeyboard.h"

namespace JourneyOfDreams
{
    void GUI::Initialize()
    { // Add an on-screen keyboard to every GUI.
        AddWidget("OnScreenKeyboard", std::make_shared<OnScreenKeyboard>());
    }

    void GUI::ShowKeyboard()
    { // Show the on-screen keyboard.
        GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Show();
    }

    void GUI::HideKeyboard()
    { // Hide the on-screen keyboard.
        GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
    }

    void GUI::Update()
    {
        GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->BringToFront();

        if (_<MouseInput>().LeftButton().Pressed()
            && !GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->MouseOver())
        {
            SetFocusedWidget(nullptr);
        }

        for ( // Update all child widgets in the same order as they have been added.
            auto &entry : ChildWidgets())
            entry.widget->Update();

        DestroyMarkedWidgets(); // Destroy all widgets that should be destroyed.

        InsertWaitingWidgets(); // Insert new widgets that are waiting to be inserted.

        if ( // Focus next widget on pressing the tab key.
            _<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        {
            FocusNextWidget();
        }

        _<KeyboardInput>().ClearTextInput(); // Clear all typed text input as it has already been handled by
                                             // the GUIs widgets.

        if (FocusedWidget() == nullptr)
        {
            GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
        }
    }

    void GUI::Render()
    {
        for ( // Render all widgets in the same order as they have been added.
            auto &entry : ChildWidgets())
            entry.widget->Render();
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier)
    {
        for ( // Search in all widgets recursively for the widget with the specified name.
            auto &entry : GetChildWidgetsRecursively())
        {
            if ( // If widget name hash is found.
                entry.id == Hash(nameIdentifier))
            {
                // Return the widget.
                return entry.widget;
            }
        }

        return nullptr; // Widget with the specified name not found.
    }

    void GUI::FocusNextWidget()
    {
        if (ChildWidgets().empty()) // No widgets exist to focus.
        {
            return;
        }

        auto widget = FocusedWidget(); // Get currently focused widget.

        for ( // Search through all widgets recursively for the next widget to focus.
            auto &entry : GetChildWidgetsRecursively())
        {
            if ( // If no widget is currently focused, return first focusable widget.
                widget == nullptr && entry.widget->Focusable())
            {
                widget = entry.widget;

                break;
            }
            else if ( // If a widget is currently focused, return the first focusable widget which does not
                      // equal to the currently focused.
                widget != nullptr && entry.widget->Focusable() && widget != entry.widget)
            {
                widget = entry.widget;

                break;
            }
        }

        SetFocusedWidget(widget); // Focus the selected widget.
    }

    std::shared_ptr<GUIWidget> GUI::FocusedWidget()
    { // Getter
        return m_focusedWidget;
    }

    void GUI::SetFocusedWidget(std::shared_ptr<GUIWidget> focusedWidget)
    { // Setter
        m_focusedWidget = focusedWidget;
    }
}
