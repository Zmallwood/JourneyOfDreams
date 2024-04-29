#include "Cursor.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace JourneyOfDreams
{
    Cursor::Cursor()
    {
        // Allocate render ID for the image of the cursor.
        m_ridCursorImage = _<ImageRenderer>().NewImage();

        // Hide default system cursor when mouse is inside the game canvas.
        SDL_ShowCursor(SDL_DISABLE);
    }

    void Cursor::ResetStyle()
    {
        // Reset the cursor style to Default at beginning of each frame.
        m_style = CursorStyles::Default;
    }

    void Cursor::Render()
    {
        // Get current mouse position.
        auto mousePos = GetMousePosition();

        // Determine cursor image dimensions.
        auto cursorWidth = m_cursorSize;
        auto cursorHeight = ConvertWidthToHeight(m_cursorSize);

        // Determine cursor image position.
        auto cursorX = mousePos.x - cursorWidth / 2;
        auto cursorY = mousePos.y - cursorHeight / 2;

        // Combine position and dimensions into the draw area.
        auto cursorArea = RectF{ cursorX, cursorY, cursorWidth, cursorHeight };

        // Get the cursor image corresponding to the current cursor style.
        auto cursorImage = m_cursorImages.at(m_style);

        // Draw the cursor image at the draw area with the resource ID.
        _<ImageRenderer>().DrawImage(m_ridCursorImage, cursorImage, cursorArea);
    }

    void Cursor::SetStyle(CursorStyles style)
    {
        m_style = style;
    }
}
