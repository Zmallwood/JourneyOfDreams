#pragma once

#include "CursorStyles.h"

namespace zw
{
    class Cursor
    {
      public:
        Cursor();
        void Render();

      private:
        CursorStyles m_style{ CursorStyles::Default };
        RID m_ridCursorImage{};
        float m_cursorSize{ 0.05f };
        const std::map<CursorStyles, std::string> m_cursorImages{
            { CursorStyles::Default, "CursorDefault" },
            { CursorStyles::Hovering, "CursorHovering" },
            { CursorStyles::Rotating, "CursorRotating" },
            { CursorStyles::Attacking, "CursorAttacking" }
        };
    };
}