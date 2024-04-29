#include "Cursor.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace JourneyOfDreams
{
    Cursor::Cursor()
    {
        m_ridCursorImage = _<ImageRenderer>().NewImage(); // Allocate render ID for the image of the cursor.

        SDL_ShowCursor(SDL_DISABLE); // Hide default system cursor when mouse is inside the game canvas.
    }

    void Cursor::ResetStyle()
    {
        m_style = CursorStyles::Default; // Reset the cursor style to Default at beginning of each frame.
    }

    void Cursor::Render()
    {
        auto mousePos = GetMousePosition(); // Get current mouse position.

        auto cursorWidth = m_cursorSize;                        // Determine cursor image width
        auto cursorHeight = ConvertWidthToHeight(m_cursorSize); // and height

        auto cursorX = mousePos.x - cursorWidth / 2;  // Determine cursor image x position.
        auto cursorY = mousePos.y - cursorHeight / 2; // Determine cursor image y position.

        auto cursorArea = RectF{ // Combine position and dimensions into the draw area.
                                 cursorX, cursorY, cursorWidth, cursorHeight
        };

        auto cursorImage = // Get the cursor image corresponding to the current cursor style.
            m_cursorImages.at(m_style);

        _<ImageRenderer>().DrawImage( // Draw the cursor image at the draw area with the resource ID.
            m_ridCursorImage, cursorImage, cursorArea);
    }

    void Cursor::SetStyle(CursorStyles style)
    {
        m_style = style;
    }
}
