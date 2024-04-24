#pragma once

#include "GUIWidget.h"

namespace zw
{
    /// Manages GUI widgets for a scene.
    class GUI : public GUIWidget
    {
      public:
        /// Update and manage adding/removing/focusing of the GUI widgets.
        void Update() override;

        /// Render the GUI widgets.
        void Render() override;

        /// Get widget by name, casted to T pointer.
        template <class T>
        std::shared_ptr<T> GetWidget(const std::string &nameIdentifier)
        {
            return static_pointer_cast<T>(GetWidget(nameIdentifier));
        }

        /// Focused widget getter.
        auto FocusedWidget()
        {
            return m_focusedWidget;
        }

        /// Focused widget setter.
        void SetFocusedWidget(std::shared_ptr<GUIWidget> focusedWidget)
        {
            m_focusedWidget = focusedWidget;
        }

      private:
        /// Focus next widget in the GUI, which will receive the typed text input.
        void FocusNextWidget();

        /// Get widget by name returned as a widget pointer.
        std::shared_ptr<GUIWidget> GetWidget(const std::string &nameIdentifier);

        /// Currently focused widget, nullptr if none is focused.
        std::shared_ptr<GUIWidget> m_focusedWidget{};
    };
}
