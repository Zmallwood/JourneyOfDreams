// Copyright (c) 2024 Andreas Åkerberg.

#include "Cursor.h"
#include "Core/Engine/Graphics/Graphics.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"
//
//  Cursor class implementation.
//
namespace JourneyOfDreams
{
   Cursor::Cursor() {
      //allocate render ID for the image of the cursor
      m_ridCursorImage = _<ImageRenderer>().NewImage();
      //hide default system cursor when mouse is inside the game canvas
      SDL_ShowCursor(SDL_DISABLE);
      glfwSetInputMode(_<Graphics>().Window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
   }
   void Cursor::ResetStyle() {
      //reset the cursor style to Default at beginning of each frame
      m_style = CursorStyles::Default;
   }
   void Cursor::Render() {
      //get current mouse position
      auto mousePos = GetMousePosition();
      //determine cursor image width and height
      auto cursorWidth = m_cursorSize;
      auto cursorHeight = ConvertWidthToHeight(m_cursorSize);
      //determine cursor image position
      auto cursorX = mousePos.x - cursorWidth / 2;
      auto cursorY = mousePos.y - cursorHeight / 2;
      //combine position and dimensions into the draw area
      auto cursorArea = RectF{ cursorX, cursorY, cursorWidth, cursorHeight };
      //get the cursor image corresponding to the current cursor style
      auto cursorImage = m_cursorImages.at(m_style);
      //draw the cursor image at the draw area with the resource ID
      _<ImageRenderer>().DrawImage(m_ridCursorImage, cursorImage, cursorArea);
   }
   void Cursor::SetStyle(CursorStyles style) {
      //setter
      m_style = style;
   }
} // namespace JourneyOfDreams
