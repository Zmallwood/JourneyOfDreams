//  Copyright (C) 2024 Andreas Åkerberg

#include "GUI.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "GUIWidget.h"
#include "OnScreenKeyboard.h"

namespace JourneyOfDreams
{
    void GUI::Initialize()
    {
        /*
        ** Add an on-screen keyboard to every GUI. */
        AddWidget("OnScreenKeyboard", std::make_shared<OnScreenKeyboard>());
    }

    void GUI::ShowKeyboard()
    {
        /*
        ** Show the on-screen keyboard. */
        GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Show();
    }

    void GUI::HideKeyboard()
    {
        /*
        ** Hide the on-screen keyboard. */
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
        /*
        ** Update all child widgets in the same order as they have been added. */
        for (auto &entry : ChildWidgets())
        {
            entry.widget->Update();
        }
        /*
        ** Destroy all widgets that should be destroyed. */
        DestroyMarkedWidgets();
        /*
        ** Insert new widgets that are waiting to be inserted. */
        InsertWaitingWidgets();
        /*
        ** Focus next widget on pressing the tab key. */
        if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_TAB))
        {
            FocusNextWidget();
        }
        /*
        ** Clear all typed text input as it has already been handled by the GUIs widgets. */
        _<KeyboardInput>().ClearTextInput();

        /*
        ** Dont show on-screen keyboard if no widget is focused. */
        if (FocusedWidget() == nullptr)
        {
            GetWidget<OnScreenKeyboard>("OnScreenKeyboard")->Hide();
        }
    }

    void GUI::Render()
    {
        /*
        ** Render all widgets in the same order as they have been added. */
        for (auto &entry : ChildWidgets())
        {
            entry.widget->Render();
        }
    }

    std::shared_ptr<GUIWidget> GUI::GetWidget(const std::string &nameIdentifier)
    {
        /*
        ** Search in all widgets recursively for the widget with the specified name. */
        for (auto &entry : GetChildWidgetsRecursively())
        {
            /*
            ** If widget name hash is found. */
            if (entry.id == Hash(nameIdentifier))
            {
                /*
                ** Return the widget. */
                return entry.widget;
            }
        }
        /*
        ** Widget with the specified name not found. */
        return nullptr;
    }

    void GUI::FocusNextWidget()
    {
        /*
        ** No widgets exist to focus. */
        if (ChildWidgets().empty())
        {
            return;
        }
        /*
        ** Get currently focused widget. */
        auto widget = FocusedWidget();
        /*
        ** Search through all widgets recursively for the next widget to focus. */
        for (auto &entry : GetChildWidgetsRecursively())
        {
            /*
            ** If no widget is currently focused, return first focusable widget. */
            if (widget == nullptr && entry.widget->Focusable())
            {
                widget = entry.widget;

                break;
            }
            /*
            ** If a widget is currently focused, return the first focusable widget which does not equal to the
            ** currently focused. */
            else if (widget != nullptr && entry.widget->Focusable() && widget != entry.widget)
            {
                widget = entry.widget;

                break;
            }
        }
        /*
        ** Focus the selected widget. */
        SetFocusedWidget(widget);
    }

    std::shared_ptr<GUIWidget> GUI::FocusedWidget()
    {
        /*
        ** Getter */
        return m_focusedWidget;
    }

    void GUI::SetFocusedWidget(std::shared_ptr<GUIWidget> focusedWidget)
    {
        /*
        ** Setter */
        m_focusedWidget = focusedWidget;
    }
}
