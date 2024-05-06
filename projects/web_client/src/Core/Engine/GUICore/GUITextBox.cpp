/* Copyright (c) 2024 Andreas Åkerberg. */

#include "GUITextBox.h"
#include "Core/Engine/Cursor/Cursor.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/OnScreenKeyboard.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

/* GUITextBox class implementation. */

namespace JourneyOfDreams
{
  GUITextBox::GUITextBox(RectF area, ColorF textColor, bool passwordMode)
      : GUIWidget(area),
        m_textColor(textColor),
        m_cursorHeight(area.h - 2 * Padding()),
        m_managedTextLine(area.w - 2 * Padding(), passwordMode) {
    /* 1) Allocate graphics resources.
     * 2) Set default widget properties. */
    m_ridBackground = _<ImageRenderer>().NewImage();
    m_ridText = _<TextRenderer>().NewString();
    m_ridCursorImage = _<ImageRenderer>().NewImage();
    SetDrawBackground(false);
    SetDrawBorders(false);
    SetBackgroundImage("GUIDefaultTextBoxBackground");
    SetFocusable(true);
  }

  void GUITextBox::TypeCharacter(char character) {
    /* Type a character into the text box. */
    m_managedTextLine.InsertCharacter(character);
  }

  void GUITextBox::UpdateDerived() {
    /* 1) If mouse is hovering this text box.
     * 2) Change cursor symbol.
     * 3) If left mouse button is also pressed.
     * 4) Give focus
     * 5) And set the text cursor position in the text box to where
     *    it was clicked. */
    auto mousePos = GetMousePosition();
    if (GetFinalArea().Contains(mousePos)) {
      _<Cursor>().SetStyle(CursorStyles::TextInput);
      if (_<MouseInput>().LeftButton().Pressed()) {
        Focus();
        auto localMousePosX = mousePos.x - GetFinalPosition().x - Padding();
        m_managedTextLine.SetCursorPositionFromLocalX(localMousePosX);
      }
    }

    if (HasFocus()) {
      /* 1) Pick all the text typed on keyboard and insert into this text box.
       * 2) Add left arrow key functionality
       * 3) Add right arrow key functionality.
       * 4) Add backspace key erase functionality.
       * 5) Add delete key erase functionality.
       * 6) Add home key functionality.
       * 7) Add end key functionality. */
      auto textInput = _<KeyboardInput>().PickTextInput();
      m_managedTextLine.InsertText(textInput);
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_LEFT)) {
        m_managedTextLine.TryMoveCursorLeft();
      }
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_RIGHT)) {
        m_managedTextLine.TryMoveCursorRight();
      }
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_BACKSPACE)) {
        m_managedTextLine.TryDeleteLeft();
      }
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_DELETE)) {
        m_managedTextLine.TryDeleteRight();
      }
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_HOME)) {
        m_managedTextLine.MoveCursorToStart();
      }
      if (_<KeyboardInput>().KeyHasBeenFiredPickResult(GLFW_KEY_END)) {
        m_managedTextLine.MoveCursorToEnd();
      }
    }
  }

  void GUITextBox::RenderDerived() {
    /* 1) Draw textbox background.
     * 2) Get canvas position for the text, to which the text
     *    will berendered.
     * 3) Get only the visible part of the text in the text box.
     * 4) Draw the text at the position. */
    _<ImageRenderer>().DrawImage(m_ridBackground, BackgroundImage(),
                                 GetFinalArea());
    auto finalPosition = GetFinalPosition();
    auto textX = finalPosition.x + Padding();
    auto textY = finalPosition.y;
    auto textToRender = m_managedTextLine.GetAppearedText();
    _<TextRenderer>().DrawString(m_ridText, textToRender, {textX, textY},
                                 m_textColor, false, FontSizes::_20);
    /* 1) with regards to focus and the cursor blinking effect.
     * 2) If so, get the canvas x position to where text cursor.
     *    will be drawn.
     * 3) The canvas y position is just at the top of the textbox with some
     *    added padding.
     * 4) Render the text cursor. */
    bool cursorVisible;
    if (HasFocus() && (Ticks() - TicksTimeGotFocus()) % 1000 < 500) {
      cursorVisible = true;
    } else {
      cursorVisible = false;
    }
    if (cursorVisible) {
      auto cursorX =
          finalPosition.x +
          _<TextRenderer>()
              .MeasureString(textToRender.substr(
                                 0, m_managedTextLine.AppearedCursorPosition()),
                             FontSizes::_20)
              .w -
          k_cursorWidth + Padding();
      auto cursorY = finalPosition.y + Padding();
      _<ImageRenderer>().DrawImage(
          m_ridCursorImage, k_cursorImage,
          RectF{cursorX, cursorY, k_cursorWidth, m_cursorHeight});
    }
  }

  std::string GUITextBox::GetText() {
    return m_managedTextLine.Text();
  }

  void GUITextBox::ClearText() {
    /* Clear text in the text box. */
    m_managedTextLine.Reset();
  }

  void GUITextBox::Focus() {
    /* 1) Show on-screen keyboard (for phones) when focusing a text box.
     * 2) Call base focus logic. */
    GetParentGUI()->ShowKeyboard();
    GUIWidget::Focus();
  }
}