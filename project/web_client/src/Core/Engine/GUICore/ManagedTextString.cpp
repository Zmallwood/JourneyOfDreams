#include "ManagedTextString.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

namespace zw
{
    ManagedTextString::ManagedTextString(float maxRenderWidth) : m_maxRenderWidth(maxRenderWidth)
    {
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

            if (m_cursorPosition - m_cursorOffset > GetAppearedText().size()) {
                m_cursorOffset++;
            }
        }

        if (IsTextOverflow())
        {
            m_cursorOffset++;
            m_cursorRightClip = 0;
            while (IsTextOverflow())
            {
                m_cursorRightClip++;
            }
        }

        if (m_cursorPosition - m_cursorOffset == GetAppearedText().size() + 1 && m_cursorPosition <= m_text.size())
        {
            m_cursorOffset++;
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
            m_cursorPosition--;
        }
    }

    void ManagedTextString::TryDeleteRight()
    {
        if (m_cursorPosition < m_text.size())
        {
            m_text.erase(m_cursorPosition, 1);
        }
    }

    int ManagedTextString::AppearedCursorPosition() const
    {
        return m_cursorPosition - m_cursorOffset;
    }

    bool ManagedTextString::IsTextOverflow() const
    {
        return _<TextRenderer>().MeasureString(GetAppearedText(), FontSizes::_20).w > m_maxRenderWidth;
    }

    std::string ManagedTextString::OffsetedText() const
    {
        return m_text.substr(m_cursorOffset);
    }

    std::string ManagedTextString::GetAppearedText() const
    {
        auto offsetedText = OffsetedText();
        return offsetedText.substr(0, offsetedText.size() - m_cursorRightClip);
    }
}