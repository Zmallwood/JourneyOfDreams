#include "GUIMessageBox.h"
#include "GUIButton.h"
#include "GUILabel.h"

namespace JourneyOfDreams
{
    GUIMessageBox::GUIMessageBox(PointF position, const std::string &message, const std::string &title,
                                 SizeF size, GUIAlign alignment, bool movable)
        : GUIWindow(RectF{ position.x, position.y, size.w, size.h }, title, alignment, movable),
          m_message(message)
    {
        /*
        ** Do nothing. */
    }

    void GUIMessageBox::Initialize()
    {
        /*
        ** Add a label to this window. */
        AddWidget(std::make_shared<GUILabel>(PointF{ 0.0f, 0.0f }, m_message));
        /*
        ** Add a confirm button to this window. */
        AddWidget(
            std::make_shared<GUIButton>(RectF{ 0.35f, 0.1f, 0.1f, 0.05f }, "OK", [this]() { Destroy(); }));
    }
}