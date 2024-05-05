//  Copyright (C) 2024 Andreas Åkerberg

#pragma once
#include "GUIWidget.h"

namespace JourneyOfDreams {
    /////////////////////////////////////////////////
    /// Manages GUI widgets for a scene.
    /////////////////////////////////////////////////
    class GUI : public GUIWidget {
      public:
        /////////////////////////////////////////////////
        /// Initializes the GUI by adding an
        /// OnScreenKeyboard widget.
        /////////////////////////////////////////////////
        void Initialize() override;

        /////////////////////////////////////////////////
        /// Shows the on-screen keyboard.
        /////////////////////////////////////////////////
        void ShowKeyboard();

        /////////////////////////////////////////////////
        /// Hides the on-screen keyboard.
        /////////////////////////////////////////////////
        void HideKeyboard();

        /////////////////////////////////////////////////
        /// Update and manage adding/removing/focusing
        /// of the GUI widgets.
        /////////////////////////////////////////////////
        void Update() override;

        /////////////////////////////////////////////////
        /// Render the GUI widgets.
        /////////////////////////////////////////////////
        void Render() override;

        /////////////////////////////////////////////////
        /// Get focused widget.
        ///
        /// \return Focused widget.
        /////////////////////////////////////////////////
        std::shared_ptr<GUIWidget> FocusedWidget();

        /////////////////////////////////////////////////
        /// Set focused widget.
        ///
        /// \param focusedWidget Focused widget.
        /////////////////////////////////////////////////
        void SetFocusedWidget(std::shared_ptr<GUIWidget> focusedWidget);

        /////////////////////////////////////////////////
        /// Get widget by name, casted to T pointer.
        /// \param nameIdentifier Name of the widget.
        /// \return Widget casted to T pointer.
        /////////////////////////////////////////////////
        template <class T>
        std::shared_ptr<T> GetWidget(const std::string &nameIdentifier) {
            return static_pointer_cast<T>(GetWidget(nameIdentifier));
        }

      private:
        void FocusNextWidget();
        std::shared_ptr<GUIWidget> GetWidget(const std::string &nameIdentifier);
        std::shared_ptr<GUIWidget> m_focusedWidget{};
    };
}
