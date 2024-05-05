// Copyright (c) 2024 Andreas Åkerberg.

#pragma once
#include "GUIWindow.h"

namespace journey_of_dreams {
    /////////////////////////////////////////////////
    /// Message box widget for the GUI.
    /////////////////////////////////////////////////
    class GUIMessageBox : public GUIWindow {
      public:
        /////////////////////////////////////////////////
        /// Forwards the constructor arguments to the base
        /// class and initializes the message string.
        ///
        /// \param position Position of the message box.
        /// \param message Message to display in the message box.
        /// \param title Title of the message box.
        /// \param size Size of the message box.
        /// \param alignment Alignment of the message box.
        /// \param movable Whether the message box is movable.
        /////////////////////////////////////////////////
        GUIMessageBox(PointF position, const std::string &message, const std::string &title = "Message",
                      SizeF size = k_defaultSize, GUIAlign alignment = GUIAlign::Center, bool movable = true);

        /////////////////////////////////////////////////
        /// Message box widget for the GUI.
        /////////////////////////////////////////////////
        void Initialize() override;

      private:
        std::string m_message{};
        static constexpr SizeF k_defaultSize = { 0.5f, 0.2f };
    };
}
