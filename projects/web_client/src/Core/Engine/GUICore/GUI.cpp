/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "GUIWidget.h"
#include "OnScreenKeyboard.h"

/* GUI class implementation. */

namespace JourneyOfDreams
{
  void GUI::Initialize() {
    /* Add an on-screen keyboard to every GUI. */
    AddWidget("OnScreenKeyboard", std::make_shared<OnScreenKeyboard>());
  }

  void GUI::ShowKeyboard() {
    /* Show the on-screen keyboard. */
    GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Show();
  }

  void GUI::HideKeyboard() {
    /* Hide the on-screen keyboard. */
    GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
  }

  void GUI::Update() {
    /* 1) Bring on-screen keyboard to front,
     * 2) If clicked outside on-screen keybord, unfocus
     *    currently focued widget.
     * 3) Update all child widgets in the same order as they have been added.
     * 4) Destroy all widgets that should be destroyed.
     * 5) Insert new widgets that are waiting to be inserted.
     * 6) Focus next widget on pressing the tab key.
     * 7) Clear all typed text input as it has already been handled by the GUIs
     *    widgets.
     * 8) Dont show on-screen keyboard if no widget is focused. */
    GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->BringToFront();

    if (_<MouseInput>().LeftButton().Pressed() &&
        !GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->MouseOver()) {
      SetFocusedWidget(nullptr);
    }
    for (auto &entry : ChildWidgets()) {
      entry.widget->Update();
    }
    DestroyMarkedWidgets();
    InsertWaitingWidgets();
    if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_TAB)) {
      FocusNextWidget();
    }
    _<KeyboardInput>().ClearTextInput();

    if (FocusedWidget() == nullptr) {
      GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
    }
  }

  void GUI::Render() {
    /* Render all widgets in the same order as they have been added. */
    for (auto &entry : ChildWidgets()) {
      entry.widget->Render();
    }
  }

  std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier) {
    /* 1) Search in all widgets recursively for the widget with
     *    the specified name.
     * 2) If widget name hash is found.
     * 3) Return the widget.
     * 4) Widget with the specified name not found. */
    for (auto &entry : GetChildWidgetsRecursively()) {
      if (entry.id == Hash(nameIdentifier)) {
        return entry.widget;
      }
    }
    return nullptr;
  }

  void GUI::FocusNextWidget() {
    /* 1) Return if no widgets exist to focus.
     * 2) Search through all widgets recursively for the next widget to focus.
     * 3) Get currently focused widget.
     * 4) If no widget is currently focused, return first focusable widget.
     * 5) If a widget is currently focused, return the first focusable widget
     *    which does not equal to the currently focused.
     * 6) Focus the selected widget. */
    if (ChildWidgets().empty()) {
      return;
    }
    auto widget = FocusedWidget();
    for (auto &entry : GetChildWidgetsRecursively()) {
      if (widget == nullptr && entry.widget->Focusable()) {
        widget = entry.widget;

        break;
      } else if (widget != nullptr && entry.widget->Focusable() &&
                 widget != entry.widget) {
        widget = entry.widget;

        break;
      }
    }
    SetFocusedWidget(widget);
  }

  std::shared_ptr<GUIWidget> GUI::FocusedWidget() {
    return m_focusedWidget;
  }

  void GUI::SetFocusedWidget(std::shared_ptr<GUIWidget> focusedWidget) {
    m_focusedWidget = focusedWidget;
  }
}
