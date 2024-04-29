#include "ManagedTextString.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace JourneyOfDreams
{
    ManagedTextString::ManagedTextString(float maxRenderWidth, bool passwordMode)
        : m_maxRenderWidth(maxRenderWidth), m_passwordMode(passwordMode)
    { // Do nothing.
    }

    void ManagedTextString::InsertText(const std::string &text)
    {
        if (text.empty())
        {
            return;
        }
        m_text.insert(m_cursorPosition, text);
        m_cursorPosition += text.size();
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::InsertCharacter(char c)
    {
        m_text.insert(m_cursorPosition, 1, c);
        m_cursorPosition++;
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::TryMoveCursorLeft()
    {
        if (m_cursorPosition > 0)
        {
            m_cursorPosition--;
        }
        if (m_cursorOffset > 0 && m_cursorPosition < m_cursorOffset)
        {
            m_cursorOffset--;
        }
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    void ManagedTextString::TryMoveCursorRight()
    {
        if (m_cursorPosition < m_text.size())
        {
            m_cursorPosition++;
            if (m_cursorPosition - m_cursorOffset > GetAppearedText().size())
            {
                m_cursorOffset++;
            }
        }
        if (IsTextOverflow())
        {
            m_cursorRightClip = 0;
            while (IsTextOverflow())
            {
                m_cursorRightClip++;
            }
        }
        if (m_cursorPosition - m_cursorOffset == GetAppearedText().size() + 1
            && m_cursorPosition <= m_text.size())
        {
            m_cursorRightClip = 0;
            while (IsTextOverflow())
            {
                m_cursorRightClip++;
            }
        }
    }

    void ManagedTextString::TryDeleteLeft()
    {
        if (m_cursorPosition > 0)
        {
            m_text.erase(m_cursorPosition - 1, 1);
            TryMoveCursorLeft();
            m_cursorOffset = std::max(0, m_cursorOffset - 1);
            if (m_cursorPosition == m_cursorOffset)
            {
                m_cursorPosition++;
            }
        }
    }

    void ManagedTextString::TryDeleteRight()
    {
        if (m_cursorPosition < m_text.size())
        {
            m_text.erase(m_cursorPosition, 1);
        }
        m_cursorRightClip = 0;
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    int ManagedTextString::AppearedCursorPosition() const
    { // Return cursor position as appeared with regard to the offset.
        return m_cursorPosition - m_cursorOffset;
    }

    bool ManagedTextString::IsTextOverflow() const
    { // Return true if text is overflowed.
        return _<TextRenderer>().MeasureString(GetAppearedText(), FontSizes::_20).w > m_maxRenderWidth;
    }

    std::string ManagedTextString::OffsetedText() const
    { // Return text with regard to the offset.
        return m_text.substr(m_cursorOffset);
    }

    std::string ManagedTextString::GetAppearedText() const
    {
        auto offsetedText = OffsetedText();
        auto clippedText = offsetedText.substr(0, offsetedText.size() - m_cursorRightClip);
        auto result = clippedText;
        if (m_passwordMode)
        {
            result = std::string(result.size(), '*');
        }
        return result;
    }

    void ManagedTextString::MoveCursorToStart()
    {
        m_cursorPosition = 0;
        m_cursorOffset = 0;
        m_cursorRightClip = 0;
        while (IsTextOverflow())
        {
            m_cursorRightClip++;
        }
    }

    void ManagedTextString::MoveCursorToEnd()
    {
        m_cursorPosition = m_text.size();
        m_cursorOffset = 0;
        m_cursorRightClip = 0;
        while (IsTextOverflow())
        {
            m_cursorOffset++;
        }
    }

    void ManagedTextString::SetCursorPositionFromLocalX(float xPosition)
    {
        auto textToRender = GetAppearedText();
        auto offsetedCursorPosition = 0;
        for (auto i = 0; i < textToRender.size(); i++)
        {
            auto charWidth = _<TextRenderer>().MeasureString(textToRender.substr(0, i), FontSizes::_20).w;
            auto lastCharWidth = 0.0f;
            if (i < textToRender.size())
            {
                lastCharWidth = _<TextRenderer>().MeasureString(textToRender.substr(i, 1), FontSizes::_20).w;
            }
            if (charWidth + lastCharWidth / 2 > xPosition)
            {
                break;
            }
            offsetedCursorPosition++;
        }
        m_cursorPosition = offsetedCursorPosition + m_cursorOffset;
    }

    void ManagedTextString::Reset()
    {
        m_text.clear();
        m_cursorPosition = 0;
        m_cursorOffset = 0;
        m_cursorRightClip = 0;
    }

    int ManagedTextString::CursorPosition() const
    { // Getter
        return m_cursorPosition;
    }

    std::string ManagedTextString::Text() const
    { // Getter
        return m_text;
    }
}