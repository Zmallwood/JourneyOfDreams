#include "GUITextBox.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Input/MouseInput.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    GUITextBox::GUITextBox(RectF area, ColorF textColor, bool passwordMode)
        : GUIWidget(area), m_textColor(textColor), m_cursorHeight(area.h - 2 * Padding()),
          m_passwordMode(passwordMode), m_managedTextLine(area.w - 2 * Padding())
    {
        m_ridBackground = _<ImageRenderer>().NewImage();
        m_ridText = _<TextRenderer>().NewString();
        m_ridCursorImage = _<ImageRenderer>().NewImage();

        SetDrawBackground(false);
        SetDrawBorders(false);
        SetBackgroundImage("GUIDefaultTextBoxBackground");
        SetFocusable(true);
    }

    void GUITextBox::UpdateDerived()
    {
        auto mousePos = GetMousePosition();

        if (GetFinalArea().Contains(mousePos))
        {
            if (_<MouseInput>().LeftButton().Pressed())
            {
                Focus();
            }
        }

        if (HasFocus())
        {
            auto textInput = _<KeyboardInput>().PickTextInput();

            m_managedTextLine.InsertText(textInput);

            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_LEFT))
            {
                m_managedTextLine.TryMoveCursorLeft();
            }
            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_RIGHT))
            {
                m_managedTextLine.TryMoveCursorRight();
            }
            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_BACKSPACE))
            {
                m_managedTextLine.TryDeleteLeft();
            }
            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_DELETE))
            {
                m_managedTextLine.TryDeleteRight();
            }
            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_HOME))
            {
                m_managedTextLine.MoveCursorToStart();
            }
            if (_<KeyboardInput>().KeyHasBeenFiredPickResult(SDLK_END))
            {
                m_managedTextLine.MoveCursorToEnd();
            }
        }
    }

    void GUITextBox::RenderDerived()
    {
        _<ImageRenderer>().DrawImage(m_ridBackground, BackgroundImage(), GetFinalArea());

        auto finalPosition = GetFinalPosition();

        auto textX = finalPosition.x + Padding();
        auto textY = finalPosition.y;

        auto textToRender = m_managedTextLine.GetAppearedText();

        if (m_passwordMode)
        {
            textToRender = std::string(textToRender.size(), '*');
        }

        _<TextRenderer>().DrawString(m_ridText, textToRender, { textX, textY }, m_textColor, false,
                                     FontSizes::_20);

        auto cursorX
            = finalPosition.x
              + _<TextRenderer>()
                    .MeasureString(textToRender.substr(0, m_managedTextLine.AppearedCursorPosition()),
                                   FontSizes::_20)
                    .w
              - k_cursorWidth + Padding();
        auto cursorY = finalPosition.y + Padding();

        bool cursorVisible;

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
            _<ImageRenderer>().DrawImage(m_ridCursorImage, k_cursorImage,
                                         RectF{ cursorX, cursorY, k_cursorWidth, m_cursorHeight });
        }
    }
}