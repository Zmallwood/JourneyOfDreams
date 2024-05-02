//  Copyright (C) 2024 Andreas Åkerberg

#include "ManagedTextString.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace JourneyOfDreams
{
    ManagedTextString::ManagedTextString(float maxRenderWidth, bool passwordMode)
        : m_maxRenderWidth(maxRenderWidth), m_passwordMode(passwordMode)
    {
        /*
        ** Do nothing. */
    }

    void ManagedTextString::InsertText(const std::string &text)
    {
        /*
        ** Cancel if there is nothing to insert. */
        if (text.empty())
        {
            return;
        }
        /*
        ** Insert text and reposition text cursor. */
        m_text.insert(m_cursorPosition, text);
        m_cursorPosition += text.size();
        /*
        ** Increase offset while text end is outside visible field. */
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::InsertCharacter(char c)
    {
        /*
        ** Insert character and reposition text cursor. */
        m_text.insert(m_cursorPosition, 1, c);
        m_cursorPosition++;
        /*
        ** Increase offset while text end is outside visible field. */
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::TryMoveCursorLeft()
    {
        /*
        ** Try move cursor to the left. */
        if (m_cursorPosition > 0)
        {
            m_cursorPosition--;
        }
        /*
        ** If cursor is now outside visible field, decrease offset. */
        if (m_cursorOffset > 0 && m_cursorPosition < m_cursorOffset)
        {
            m_cursorOffset--;
        }
        /*
        ** Increase right side clip until no characters are shown outside visible field. */
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    void ManagedTextString::TryMoveCursorRight()
    {
        /*
        ** Try move cursor to the right. */
        if (m_cursorPosition < m_text.size())
        {
            m_cursorPosition++;
            /*
            ** If offseted text is longer than the text that fits in the visible field,
            ** increase offset. */
            if (m_cursorPosition - m_cursorOffset > GetAppearedText().size())
            {
                m_cursorOffset++;
            }
        }
        /*
        ** Reset right side clip. */
        m_cursorRightClip = 0;
        /*
        ** And increase it until there is no overflow. */
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    void ManagedTextString::TryDeleteLeft()
    {
        /*
        ** If the text cursor is not at the left edge of the text. */
        if (m_cursorPosition > 0)
        {
            /*
            ** Erase the character to the left of cursor. */
            m_text.erase(m_cursorPosition - 1, 1);

            TryMoveCursorLeft();

            /*
            ** Try decrease offset by 1, but not less than 0.
            ** This makes at least one character visible to the left of
            ** cursor, which makes it easier for further left-deletions,
            ** to see which character that is being deleted. */
            m_cursorOffset = std::max(0, m_cursorOffset - 1);
        }
    }

    void ManagedTextString::TryDeleteRight()
    {
        /*
        ** Ensure cursor is not outside text. */
        if (m_cursorPosition < m_text.size())
        {
            /*
            ** Erase the character to the right of cursor. */
            m_text.erase(m_cursorPosition, 1);
        }
        /*
        ** Reset right side clip. */
        m_cursorRightClip = 0;
        /*
        ** And increase it until there is no overflow. */
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    int ManagedTextString::AppearedCursorPosition() const
    {
        /*
        ** Return cursor position as appeared with regard to the offset. */
        return m_cursorPosition - m_cursorOffset;
    }

    bool ManagedTextString::IsTextOverflow() const
    {
        /*
        ** Return true if text is overflowed. */
        return _<TextRenderer>().MeasureString(GetAppearedText(), FontSizes::_20).w > m_maxRenderWidth;
    }

    std::string ManagedTextString::OffsetedText() const
    {
        /*
        ** Return text with regard to the offset. */
        return m_text.substr(m_cursorOffset);
    }

    std::string ManagedTextString::GetAppearedText() const
    {
        /*
        ** Get offseted text, that dont include text outside
        ** of the left edge of the visible text field. */
        auto offsetedText = OffsetedText();
        /*
        ** Clip the text outside of the right edge of the visible text field. */
        auto clippedText = offsetedText.substr(0, offsetedText.size() - m_cursorRightClip);
        auto result = clippedText;
        /*
        ** Check if enabled and apply password mode. */
        if (m_passwordMode)
        {
            result = std::string(result.size(), '*');
        }
        return result;
    }

    void ManagedTextString::MoveCursorToStart()
    {
        /*
        ** Both positiong and offset must be set to 0. */
        m_cursorPosition = 0;
        m_cursorOffset = 0;
        /*
        ** Reapply right side clip. */
        m_cursorRightClip = 0;
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    void ManagedTextString::MoveCursorToEnd()
    {
        /*
        ** Set text cursor position to right side of the last character in the text. */
        m_cursorPosition = m_text.size();
        /*
        ** No need of right side clipping when we know we are at the right end of the text. */
        m_cursorRightClip = 0;
        /*
        ** Reapply cursor offset. */
        m_cursorOffset = 0;
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::SetCursorPositionFromLocalX(float xPosition)
    {
        /*
        ** Get only the visible part of the text. */
        auto textToRender = GetAppearedText();
        /*
        ** To hold the resulting cursor position, with the cursor offset subtracted. */
        auto offsetedCursorPosition = 0;
        /*
        ** Iterate through the characters of the visible text. */
        for (auto i = 0; i < textToRender.size(); i++)
        {
            /*
            ** Measure the rendered width of the substring from character index 0 to i. */
            auto leftSubStrWidth
                = _<TextRenderer>().MeasureString(textToRender.substr(0, i), FontSizes::_20).w;
            /*
            ** Measure the rendered width of the character at index i. */
            auto lastCharWidth = _<TextRenderer>().MeasureString(textToRender.substr(i, 1), FontSizes::_20).w;
            /*
            ** If the center of the currently iterated character exceeds the x position. */
            if (leftSubStrWidth + lastCharWidth / 2 > xPosition)
            {
                /*
                ** The correct character, and its index has been found. Cancel loop. */
                break;
            }
            /*
            ** The correct character, and its indx, not yet been found. Keep iterating. */
            offsetedCursorPosition++;
        }
        /*
        ** Set the final text cursor position, by just adding the cursor offset to the value. */
        m_cursorPosition = offsetedCursorPosition + m_cursorOffset;
    }

    void ManagedTextString::Reset()
    {
        /*
        ** Should not contain any text anymore. */
        m_text.clear();
        /*
        ** Cursor position can only be 0 without text. */
        m_cursorPosition = 0;
        /*
        ** There is nothing to offset without text. */
        m_cursorOffset = 0;
        /*
        ** There is nothing to clip without text. */
        m_cursorRightClip = 0;
    }

    int ManagedTextString::CursorPosition() const
    {
        /*
        ** Getter */
        return m_cursorPosition;
    }

    std::string ManagedTextString::Text() const
    {
        /*
        ** Getter */
        return m_text;
    }
}