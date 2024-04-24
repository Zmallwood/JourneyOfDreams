#pragma once

namespace zw
{
    /// Available cursor styles, each yielding a different rendered cursor image.
    enum class CursorStyles
    {
        /// Default style.
        Default,
        /// When hovering a text input field.
        TextInput,
        /// When hovering something clickable.
        Hovering,
        /// When rotating the camera in 3D view.
        Rotating,
        /// When attack is possible on mouse click.
        Attacking
    };
}
