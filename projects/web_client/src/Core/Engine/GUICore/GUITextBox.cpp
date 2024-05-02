//  Copyright (C) 2024 Andreas Åkerberg

#include "GUITextBox.h"
#include "Core/Engine/Cursor/Cursor.h"
#include "Core/Engine/GUICore/GUI.h"
#include "Core/Engine/GUICore/OnScreenKeyboard.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace JourneyOfDreams
{
    GUITextBox::GUITextBox(RectF area, ColorF textColor, bool passwordMode)
        : GUIWidget(area), m_textColor(textColor), m_cursorHeight(area.h - 2 * Padding()),
          m_managedTextLine(area.w - 2 * Padding(), passwordMode)
    {
        /*
        ** Allocate graphics resources. */
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridText = _<TextRenderer>().NewString();
        m_ridCursorImage = _<ImageRenderer>().NewImage();
        /*
        ** Set default widget properties. */
        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultTextBoxBackground");
        SetFocusable(true);
    }

    void GUITextBox::TypeCharacter(char c)
    {
        /*
        ** Type a character into the text box. */
        m_managedTextLine.InsertCharacter(c);
    }

    void GUITextBox::UpdateDerived()
    {
        // auto mousePos = GetMousePosition();
        // /*
        // ** If mouse is hovering this text box. */
        // if (GetFinalArea().Contains(mousePos))
        // {
        //     /*
        //     ** Change cursor symbol. */
        //     _<Cursor>().SetStyle(CursorStyles::TextInput);
        //     /*
        //     ** If left mouse button is also pressed. */
        //     if (_<MouseInput>().LeftButton().Pressed())
        //     {
        //         /*
        //         ** Give focus */
        //         Focus();
        //         /*
        //         ** And set the cursor position in the text box to where it was clicked. */
        //         auto localMousePosX = mousePos.x - GetFinalPosition().x - Padding();
        //         m_managedTextLine.SetCursorPositionFromLocalX(localMousePosX);
        //     }
        // }

        // if (HasFocus())
        // {
        //     /*
        //     ** Pick all the text typed on keyboard and insert into this text box. */
        //     auto textInput = _<KeyboardInput>().PickTextInput();
        //     m_managedTextLine.InsertText(textInput);
        //     /*
        //     ** Add left arrow key functionality.*/
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_LEFT))
        //     {
        //         m_managedTextLine.TryMoveCursorLeft();
        //     }
        //     /*
        //     ** Add right arrow key functionality. */
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_RIGHT))
        //     {
        //         m_managedTextLine.TryMoveCursorRight();
        //     }
        //     /*
        //     ** Add backspace key erase functionality. */
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_BACKSPACE))
        //     {
        //         m_managedTextLine.TryDeleteLeft();
        //     }
        //     /*
        //     ** Add delete key erase functionality. */
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_DELETE))
        //     {
        //         m_managedTextLine.TryDeleteRight();
        //     }
        //     /*
        //     ** Add home key erase functionality. */
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_HOME))
        //     {
        //         m_managedTextLine.MoveCursorToStart();
        //     }
        //     /*
        //     ** Add end key erase functionality. */
        //     if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_END))
        //     {
        //         m_managedTextLine.MoveCursorToEnd();
        //     }
        // }
    }

    void GUITextBox::RenderDerived()
    {
        /*
        ** Draw textbox background. */
        _<ImageRenderer>().DrawImage(m_ridBackground, BackgroundImage(), GetFinalArea());
        /*
        ** Get canvas position for the center of the text, to which the text will be rendered. */
        auto finalPosition = GetFinalPosition();
        auto textX = finalPosition.x + Padding();
        auto textY = finalPosition.y;
        /*
        ** Get only the visible part of the text in the text box. */
        auto textToRender = m_managedTextLine.GetAppearedText();
        /*
        ** Draw the text at the position. */
        _<TextRenderer>().DrawString(m_ridText, textToRender, { textX, textY }, m_textColor, false,
                                     FontSizes::_20);

        bool cursorVisible;
        /*
        ** Determine if text cursor should be rendered for this text box
        ** with regards to focus and the cursor blinking effect. */
        if (HasFocus() && (Ticks() - TicksTimeGotFocus()) % 1000 < 500)
        {
            cursorVisible = true;
        }
        else
        {
            cursorVisible = false;
        }

        if (cursorVisible)
        {
            /*
             ** Get the canvas x position in the to where text cursor will be drawn. */
            auto cursorX
                = finalPosition.x
                  + _<TextRenderer>()
                        .MeasureString(textToRender.substr(0, m_managedTextLine.AppearedCursorPosition()),
                                       FontSizes::_20)
                        .w
                  - k_cursorWidth + Padding();
            /*
            ** The canvas y position is just at the top of the textbox with some added padding. */
            auto cursorY = finalPosition.y + Padding();
            /*
            ** Render the text cursor. */
            _<ImageRenderer>().DrawImage(m_ridCursorImage, k_cursorImage,
                                         RectF{ cursorX, cursorY, k_cursorWidth, m_cursorHeight });
        }
    }

    std::string GUITextBox::GetText()
    {
        /*
        ** Getter. */
        return m_managedTextLine.Text();
    }

    void GUITextBox::ClearText()
    {
        /*
        ** Clear text in the text box. */
        m_managedTextLine.Reset();
    }

    void GUITextBox::Focus()
    {
        /*
        ** Show on-screen keyboard (for phones) when focusing a text box. */
        GetParentGUI()->ShowKeyboard();
        /*
        ** Call base focus logic. */
        GUIWidget::Focus();
    }
}