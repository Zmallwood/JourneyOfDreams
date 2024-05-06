/* Copyright (c) 2024 Andreas Åkerberg. */

#include "OnScreenKeyboard.h"
#include "GUI.h"
#include "GUIButton.h"
#include "GUIPanel.h"
#include "GUITextBox.h"

// on_screen_keyboard class implementation.

namespace JourneyOfDreams
{
  OnScreenKeyboard::OnScreenKeyboard()
      : GUIPanel({.x = 0.5f, .y = 1.0f}, {.w = 0.3f, .h = 0.15f},
                 GUIAlign::BottomCenter) {
    /*
    ** Set default widget propertis. **/
    SetVisible(false);
    SetPadding(0.0f);
  }

  void OnScreenKeyboard::Initialize() {
    /*
    ** Create panel containing the lower case buttons. **/
    auto pnlLowerCase =
        AddWidget("pnlLowerCase",
                  std::make_shared<GUIPanel>(PointF{.x = 0.0f, .y = 0.0f},
                                             SizeF{.w = 0.3f, .h = 0.15f}));
    /*
    ** Set default properties for lower case panel.**/
    pnlLowerCase->SetDrawBackground(false);
    pnlLowerCase->SetDrawBorders(false);
    /*
    ** Add buttons to the lower case panel. **/
    AddWidget("btn1",
              std::make_shared<GUIButton>(RectF{0.0f, 0.0f, 0.015f, 0.05f}, "1",
                                          [this]() { TypeCharacter('1'); }));
    AddWidget("btn2", std::make_shared<GUIButton>(
                          RectF{0.018f, 0.0f, 0.015f, 0.05f}, "2",
                          [this]() { TypeCharacter('2'); }));
    AddWidget("btn3", std::make_shared<GUIButton>(
                          RectF{0.036f, 0.0f, 0.015f, 0.05f}, "3",
                          [this]() { TypeCharacter('3'); }));
    AddWidget("btn4", std::make_shared<GUIButton>(
                          RectF{0.054f, 0.0f, 0.015f, 0.05f}, "4",
                          [this]() { TypeCharacter('4'); }));
    AddWidget("btn5", std::make_shared<GUIButton>(
                          RectF{0.072f, 0.0f, 0.015f, 0.05f}, "5",
                          [this]() { TypeCharacter('5'); }));
    AddWidget("btn6", std::make_shared<GUIButton>(
                          RectF{0.09f, 0.0f, 0.015f, 0.05f}, "6",
                          [this]() { TypeCharacter('6'); }));
    AddWidget("btn7", std::make_shared<GUIButton>(
                          RectF{0.108f, 0.0f, 0.015f, 0.05f}, "7",
                          [this]() { TypeCharacter('7'); }));
    AddWidget("btn8", std::make_shared<GUIButton>(
                          RectF{0.126f, 0.0f, 0.015f, 0.05f}, "8",
                          [this]() { TypeCharacter('8'); }));
    AddWidget("btn9", std::make_shared<GUIButton>(
                          RectF{0.144f, 0.0f, 0.015f, 0.05f}, "9",
                          [this]() { TypeCharacter('9'); }));
    AddWidget("btn0", std::make_shared<GUIButton>(
                          RectF{0.162f, 0.0f, 0.015f, 0.05f}, "0",
                          [this]() { TypeCharacter('0'); }));
  }

  void OnScreenKeyboard::Show() {
    /*
    ** Show the on-screen keyboard. **/
    SetVisible(true);
  }

  void OnScreenKeyboard::Hide() {
    /*
    ** Hide the on-screen keyboard. **/
    SetVisible(false);
  }

  void OnScreenKeyboard::TypeCharacter(char c) {
    /*
    ** Get currently focused textbox. **/
    auto gui = GetParentGUI();
    auto focusedTextBox =
        dynamic_pointer_cast<GUITextBox>(gui->FocusedWidget());
    /*
    ** If any text box is focused. */
    if (focusedTextBox) {
      /*
      ** Send the pressed character to it. **/
      focusedTextBox->TypeCharacter(c);
    }
  }
}