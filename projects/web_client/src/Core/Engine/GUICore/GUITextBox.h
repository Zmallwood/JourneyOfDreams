// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIWidget.h"
#include "ManagedTextString.h"

// gui_text_box class declaration.

namespace journey_of_dreams
{
  /////////////////////////////////////////////////
  /// A text box widget for the GUI.
  /////////////////////////////////////////////////
  class GUITextBox : public GUIWidget {
   public:
    /////////////////////////////////////////////////
    /// Initialize class members and graphical resources
    /// and setup the default appearance of the text box.
    ///
    /// \param area Area of the text box.
    /// \param textColor Color of the text.
    /// \param passwordMode Whether the text box is
    ///                     in password mode.
    /////////////////////////////////////////////////
    GUITextBox(RectF area, ColorF textColor = Colors::Wheat,
               bool passwordMode = false);

    /////////////////////////////////////////////////
    /// Update the text box's state.
    /////////////////////////////////////////////////
    void UpdateDerived() override;

    /////////////////////////////////////////////////
    /// Render the text box.
    /////////////////////////////////////////////////
    void RenderDerived() override;

    /////////////////////////////////////////////////
    /// Get the text currently in the text field.
    ///
    /// \return The text in the text field.
    /////////////////////////////////////////////////
    std::string GetText();

    /////////////////////////////////////////////////
    /// Clears the text in the text field.
    /////////////////////////////////////////////////
    void ClearText();

    /////////////////////////////////////////////////
    /// Give focus to the text box, getting all the
    /// text input.
    /////////////////////////////////////////////////
    void Focus() override;

    /////////////////////////////////////////////////
    /// Type a single character into the text box.
    ///
    /// \param c Character to type.
    /////////////////////////////////////////////////
    void TypeCharacter(char c);

   private:
    RID m_ridBackground{};
    RID m_ridText{};
    RID m_ridCursorImage{};
    ManagedTextString m_managedTextLine;
    ColorF m_textColor{Colors::Wheat};
    float m_cursorHeight{0.01f};
    const std::string k_cursorImage{"GUITextBoxCursor"};
    const float k_cursorWidth{0.002f};
  };
} // namespace journey_of_dreams
