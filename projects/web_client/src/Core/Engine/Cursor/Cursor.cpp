#include "Cursor.h"
#include "Core/Engine/Rendering/ImageRendering/ImageRenderer.h"

namespace zw {
  Cursor::Cursor() {
    m_ridCursorImage = _<ImageRenderer>().NewImage();
    SDL_ShowCursor(SDL_DISABLE);
  }

  void Cursor::ResetStyle() {
    m_style = CursorStyles::Default;
  }
  
  void Cursor::Render() {
    auto mousePos = GetMousePosition();
    auto cursorWidth = m_cursorSize;
    auto cursorHeight = ConvertWidthToHeight(m_cursorSize);
    auto cursorX = mousePos.x - cursorWidth / 2;
    auto cursorY = mousePos.y - cursorHeight / 2;
    auto cursorArea = RectF{ cursorX, cursorY, cursorWidth, cursorHeight };
    auto cursorImage = m_cursorImages.at(m_style);
    _<ImageRenderer>().DrawImage(m_ridCursorImage, cursorImage, cursorArea);
  }
}