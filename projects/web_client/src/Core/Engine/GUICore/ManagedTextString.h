#pragma once

namespace zw {
  class ManagedTextString {
   public:
    ManagedTextString(float maxRenderWidth = 1.0f, bool passwordMode = false);

    void InsertText(const std::string &text);

    void TryMoveCursorLeft();

    void TryMoveCursorRight();

    void TryDeleteLeft();

    void TryDeleteRight();

    int AppearedCursorPosition() const;

    std::string GetAppearedText() const;

    void MoveCursorToStart();

    void MoveCursorToEnd();

    void SetCursorPositionFromLocalX(float localMouseX);

    void Reset();

    auto CursorPosition() const {
      return m_cursorPosition;
    }

    auto Text() const {
      return m_text;
    }

   private:
    std::string OffsetedText() const;

    bool IsTextOverflow() const;

    std::string m_text{};
    int m_cursorPosition{ 0 };
    int m_cursorOffset{ 0 };
    int m_cursorRightClip{ 0 };
    float m_maxRenderWidth{ 1.0f };
    bool m_passwordMode{ false };
  };
}