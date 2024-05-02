//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Manages a text string with manipulation
    /// operations and navigation with a cursor.
    /////////////////////////////////////////////////
    class ManagedTextString
    {
      public:
        /////////////////////////////////////////////////
        /// Initializes class members.
        ///
        /// \param maxRenderWidth The maximum width of the
        ///                       rendererd text.
        /// \param passwordMode Whether the text should be
        ///                     displayed as a password.
        /////////////////////////////////////////////////
        ManagedTextString(float maxRenderWidth = 1.0f, bool passwordMode = false);

        /////////////////////////////////////////////////
        /// Inserts text at the current cursor position.
        ///
        /// \param text The text to insert.
        /////////////////////////////////////////////////
        void InsertText(const std::string &text);

        /////////////////////////////////////////////////
        /// Insert a character at the current cursor
        /// position.
        ///
        /// \param c The character to insert.
        /////////////////////////////////////////////////
        void InsertCharacter(char c);

        /////////////////////////////////////////////////
        /// Moves the cursor one character to the left
        /// if possible.
        /////////////////////////////////////////////////
        void TryMoveCursorLeft();

        /////////////////////////////////////////////////
        /// Moves the cursor one character to the right
        /// if possible.
        /////////////////////////////////////////////////
        void TryMoveCursorRight();

        /////////////////////////////////////////////////
        /// Deletes the character to the left of the
        /// cursor if possible.
        /////////////////////////////////////////////////
        void TryDeleteLeft();

        /////////////////////////////////////////////////
        /// Deletes the character to the right of the
        /// cursor if possible.
        /////////////////////////////////////////////////
        void TryDeleteRight();

        /////////////////////////////////////////////////
        /// Gets the cursor position in the text that
        /// is currently being displayed with regards
        /// to the cursor offset.
        ///
        /// \return The cursor position.
        /////////////////////////////////////////////////
        int AppearedCursorPosition() const;

        /////////////////////////////////////////////////
        /// Gets the text that is currently being
        /// displayed with regards to the cursor offset
        /// and cursor right clip.
        ///
        /// \return The text.
        /////////////////////////////////////////////////
        std::string GetAppearedText() const;

        /////////////////////////////////////////////////
        /// Moves the cursor to the start of the text.
        /////////////////////////////////////////////////
        void MoveCursorToStart();

        /////////////////////////////////////////////////
        /// Moves the cursor to the end of the text.
        /////////////////////////////////////////////////
        void MoveCursorToEnd();

        /////////////////////////////////////////////////
        /// Sets the cursor position to the character
        /// at the given x position, measured from the left
        /// edge of the text area.
        ///
        /// \param xPosition The x position.
        /////////////////////////////////////////////////
        void SetCursorPositionFromLocalX(float xPosition);

        /////////////////////////////////////////////////
        /// Clears the text, and sets position, offset
        /// and right clip to 0.
        /////////////////////////////////////////////////
        void Reset();

        /////////////////////////////////////////////////
        /// Gets the cursor position in the text.
        ///
        /// \return The cursor position.
        /////////////////////////////////////////////////
        int CursorPosition() const;

        /////////////////////////////////////////////////
        /// Gets the complete text.
        ///
        /// \return The text.
        /////////////////////////////////////////////////
        std::string Text() const;

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
