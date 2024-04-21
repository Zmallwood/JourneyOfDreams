#pragma once

#include "CursorStyles.h"

namespace zw
{
    class Cursor
    {
      public:
        Cursor();
        void ResetStyle();
        void Render();
        void SetStyle(CursorStyles style)
        {
            m_style = style;
        }

      private:
        CursorStyles m_style{ CursorStyles::Default };
        RID m_ridCursorImage{};
        float m_cursorSize{ 0.05f };
        const std::map<CursorStyles, std::string> m_cursorImages{
            { CursorStyles::Default, "CursorDefault" },
            { CursorStyles::TextInput, "CursorTextInput" },
            { CursorStyles::Hovering, "CursorHovering" },
            { CursorStyles::Rotating, "CursorRotating" },
            { CursorStyles::Attacking, "CursorAttacking" }
        };
    };
}