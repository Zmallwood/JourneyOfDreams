/* Copyright (c) 2024 Andreas Åkerberg. */

#include "ManagedTextString.h"
#include "Core/Engine/Rendering/TextRendering/TextRenderer.h"

/* GUIManagedTextString class implementation. */

namespace JourneyOfDreams
{
  ManagedTextString::ManagedTextString(float maxRenderWidth, bool passwordMode)
      : m_maxRenderWidth(maxRenderWidth), m_passwordMode(passwordMode) {
  }

  void ManagedTextString::InsertText(const std::string &text) {
    /* 1) Cancel if there is nothing to insert.
     * 2) Insert text and reposition text cursor.
     * 3) Increase offset while text end is outside visible field. */
    if (text.empty()) {
      return;
    }
    m_text.insert(m_cursorPosition, text);
    m_cursorPosition += text.size();
    while (IsTextOverflow()) {
      m_cursorOffset++;
    }
  }

  void ManagedTextString::InsertCharacter(char c) {
    /* 1) Insert character and reposition text cursor.
     * 2) Increase offset while text end is outside visible field. */
    m_text.insert(m_cursorPosition, 1, c);
    m_cursorPosition++;
    while (IsTextOverflow()) {
      m_cursorOffset++;
    }
  }

  void ManagedTextString::TryMoveCursorLeft() {
    /* 1) Try move cursor to the left.
     * 2) If cursor is now outside visible field, decrease offset.
     * 3) Increase right side clip until no characters are shown
     *    outside visible field. */
    if (m_cursorPosition > 0) {
      m_cursorPosition--;
    }
    if (m_cursorOffset > 0 && m_cursorPosition < m_cursorOffset) {
      m_cursorOffset--;
    }
    while (IsTextOverflow()) {
      m_cursorRightClip++;
    }
  }

  void ManagedTextString::TryMoveCursorRight() {
    /* 1) Try move cursor to the right.
     * 2) If offseted text is longer than the text that fits in the visible
     *    field, increase offset.
     * 3) Reset right side clip.
     * 4) And increase it until there is no overflow. */
    if (m_cursorPosition < m_text.size()) {
      m_cursorPosition++;
      if (m_cursorPosition - m_cursorOffset > GetAppearedText().size()) {
        m_cursorOffset++;
      }
    }
    m_cursorRightClip = 0;
    while (IsTextOverflow()) {
      m_cursorRightClip++;
    }
  }

  void ManagedTextString::TryDeleteLeft() {
    /* 1) If the text cursor is not at the left edge of the text.
     * 2) Then erase the character to the left of cursor.
     * 3) Try decrease offset by 1, but not less than 0.
     *    This makes at least one character visible to the left of
     *    cursor, which makes it easier for further left-deletions,
     *    to see which character that is being deleted. */
    if (m_cursorPosition > 0) {
      m_text.erase(m_cursorPosition - 1, 1);
      TryMoveCursorLeft();
      m_cursorOffset = std::max(0, m_cursorOffset - 1);
    }
  }

  void ManagedTextString::TryDeleteRight() {
    /* 1) Ensure cursor is not outside text.
     * 2) Erase the character to the right of cursor.
     * 3) Reset right side clip.
     * 4) And increase it until there is no overflow. */
    if (m_cursorPosition < m_text.size()) {
      m_text.erase(m_cursorPosition, 1);
    }
    m_cursorRightClip = 0;
    while (IsTextOverflow()) {
      m_cursorRightClip++;
    }
  }

  int ManagedTextString::AppearedCursorPosition() const {
    /* Return cursor position as appeared with regard to the offset. */
    return m_cursorPosition - m_cursorOffset;
  }

  bool ManagedTextString::IsTextOverflow() const {
    /* Return true if text is overflowed. */
    return _<TextRenderer>()
               .MeasureString(GetAppearedText(), FontSizes::_20)
               .w > m_maxRenderWidth;
  }

  std::string ManagedTextString::OffsetedText() const {
    /* Return text with regard to the offset. */
    return m_text.substr(m_cursorOffset);
  }

  std::string ManagedTextString::GetAppearedText() const {
    /* 1) Get offseted text, that dont include text outside
     *    of the left edge of the visible text field.
     * 2) Clip the text outside of the right edge of the visible text field.
     * 3) Check if enabled and apply password mode. */
    auto offsetedText = OffsetedText();
    auto clippedText =
        offsetedText.substr(0, offsetedText.size() - m_cursorRightClip);
    auto result = clippedText;
    if (m_passwordMode) {
      result = std::string(result.size(), '*');
    }
    return result;
  }

  void ManagedTextString::MoveCursorToStart() {
    /* 1) Both positiong and offset must be set to 0.
     * 2) Reapply right side clip. */
    m_cursorPosition = 0;
    m_cursorOffset = 0;
    m_cursorRightClip = 0;
    while (IsTextOverflow()) {
      m_cursorRightClip++;
    }
  }

  void ManagedTextString::MoveCursorToEnd() {
    /* 1) Set text cursor position to right side of the last
     *    character in the text.
     * 2) No need of right side clipping when we know we are
     *    at the right end of the text.
     * 3) Reapply cursor offset.*/
    m_cursorPosition = m_text.size();
    m_cursorRightClip = 0;
    m_cursorOffset = 0;
    while (IsTextOverflow()) {
      m_cursorOffset++;
    }
  }

  void ManagedTextString::SetCursorPositionFromLocalX(float xPosition) {
    /* 1) Get only the visible part of the text.
     * 2) Declare variable to hold the resulting cursor position,
     *    with the cursor offset subtracted.
     * 3) Iterate through the characters of the visible text.
     * 4) Measure the rendered width of the substring from character
     *    index 0 to i.
     * 5) Measure the rendered width of the character at index i.
     * 6) If the center of the currently iterated character exceeds
     *    the x position:
     * 7) Then the correct character, and its index has been found. Cancel loop.
     * 8) Else, the correct character, and its index, not yet been found.
     * 9) Keep iterating.
     * 10)Set the final text cursor position, by just adding the
     *    cursor offset to the value. */
    auto textToRender = GetAppearedText();
    auto offsetedCursorPosition = 0;
    for (auto i = 0; i < textToRender.size(); i++) {
      auto leftSubStrWidth =
          _<TextRenderer>()
              .MeasureString(textToRender.substr(0, i), FontSizes::_20)
              .w;
      auto lastCharWidth =
          _<TextRenderer>()
              .MeasureString(textToRender.substr(i, 1), FontSizes::_20)
              .w;
      if (leftSubStrWidth + lastCharWidth / 2 > xPosition) {
        break;
      }
      offsetedCursorPosition++;
    }
    m_cursorPosition = offsetedCursorPosition + m_cursorOffset;
  }

  void ManagedTextString::Reset() {
    /* 1) Should not contain any text anymore.
     * 2) Cursor position can only be 0 without text.
     * 3) There is nothing to offset without text.
     * 4) There is nothing to clip without text. */
    m_text.clear();
    m_cursorPosition = 0;
    m_cursorOffset = 0;
    m_cursorRightClip = 0;
  }

  int ManagedTextString::CursorPosition() const {
    return m_cursorPosition;
  }

  std::string ManagedTextString::Text() const {
    return m_text;
  }
}