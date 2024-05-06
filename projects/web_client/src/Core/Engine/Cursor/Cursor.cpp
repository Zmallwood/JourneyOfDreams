/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Cursor.h"
#include "Core/Engine/Graphics/Graphics.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

/* Cursor class implementation. */

namespace JourneyOfDreams
{
  Cursor::Cursor() {
    /* 1) Allocate render ID for the image of the cursor.
     * 2) Hide default system cursor when mouse is inside the game canvas. */
    m_ridCursorImage = _<ImageRenderer>().NewImage();
    glfwSetInputMode(_<Graphics>().Window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  }

  void Cursor::ResetStyle() {
    /* Reset the cursor style to Default at beginning of each frame. */
    m_style = CursorStyles::Default;
  }

  void Cursor::Render() {
    /* 1) Get current mouse position.
     * 2) Determine cursor image width and height.
     * 3) Determine cursor image position.
     * 4) Combine position and dimensions into the draw area.
     * 5) Get the cursor image corresponding to the current cursor style.
     * 6) Draw the cursor image at the draw area with the resource ID. */
    auto mousePos{GetMousePosition()};
    auto cursorWidth{m_cursorSize};
    auto cursorHeight{ConvertWidthToHeight(m_cursorSize)};
    auto cursorX{mousePos.x - cursorWidth / 2};
    auto cursorY{mousePos.y - cursorHeight / 2};
    auto cursorArea{RectF{cursorX, cursorY, cursorWidth, cursorHeight}};
    auto cursorImage{m_cursorImages.at(m_style)};
    _<ImageRenderer>().DrawImage(m_ridCursorImage, cursorImage, cursorArea);
  }

  void Cursor::SetStyle(CursorStyles style) {
    m_style = style;
  }
}
