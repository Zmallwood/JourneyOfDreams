#pragma once
#include "CursorStyles.h"

namespace zw
{
    class Engine;

    /// Game mouse cursor which replaces default system cursor.
    class Cursor
    {
      public:
        /// Allocated image resource and hides default system cursor inside canvas.
        Cursor(Engine& engine);

        /// Resets cursors visual style at the beginning of each frame.
        void ResetStyle();

        /// Render the cursor image at current mouse location.
        void Render();

        /// Style setter.
        void SetStyle(CursorStyles style)
        {
            m_style = style;
        }

      private:
        /// Current cursor style, determines which cursor image is being rendered.
        CursorStyles m_style{ CursorStyles::Default };

        /// Cursor image resource ID.
        RID m_ridCursorImage{};

        /// Size of the rendered cursor image.
        float m_cursorSize{ 0.03f };

        /// Mapping of cursor image names to available cursor styles.
        const std::map<CursorStyles, std::string> m_cursorImages{
            { CursorStyles::Default, "CursorDefault" },
            { CursorStyles::TextInput, "CursorTextInput" },
            { CursorStyles::Hovering, "CursorHovering" },
            { CursorStyles::Rotating, "CursorRotating" },
            { CursorStyles::Attacking, "CursorAttacking" }
        };

        Engine &m_engine;
    };
}
