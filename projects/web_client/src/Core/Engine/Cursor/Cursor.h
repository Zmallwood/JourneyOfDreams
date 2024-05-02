//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

#include "CursorStyles.h"

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Game mouse cursor which replaces default
    /// system cursor.
    /////////////////////////////////////////////////
    class Cursor
    {
      public:
        /////////////////////////////////////////////////
        /// Allocated image resource and hides default
        /// system cursor inside canvas.
        /////////////////////////////////////////////////
        Cursor();

        /////////////////////////////////////////////////
        /// Resets cursors visual style at the beginning
        /// of each frame.
        /////////////////////////////////////////////////
        void ResetStyle();

        /////////////////////////////////////////////////
        /// Render the cursor image at current mouse location.
        /////////////////////////////////////////////////
        void Render();

        /////////////////////////////////////////////////
        /// Style setter.
        ///
        /// \param style New cursor style.
        /////////////////////////////////////////////////
        void SetStyle(CursorStyles style);

      private:
        CursorStyles m_style{ CursorStyles::Default };
        RID m_ridCursorImage{};
        float m_cursorSize{ 0.03f };
        const std::map<CursorStyles, std::string> m_cursorImages{
            { CursorStyles::Default, "CursorDefault" },
            { CursorStyles::TextInput, "CursorTextInput" },
            { CursorStyles::Hovering, "CursorHovering" },
            { CursorStyles::Rotating, "CursorRotating" },
            { CursorStyles::Attacking, "CursorAttacking" }
        };
    };
}
