// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// gui_align class declaration.

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Possible alignments for GUI widgets.
  /////////////////////////////////////////////////
  enum class GUIAlign {
    /////////////////////////////////////////////////
    /// Widget is aligned to the top left corner.
    /////////////////////////////////////////////////
    TopLeft,

    /////////////////////////////////////////////////
    /// Widget is aligned to the top center.
    /////////////////////////////////////////////////
    TopCenter,

    /////////////////////////////////////////////////
    /// Widget is aligned to the top right corner.
    /////////////////////////////////////////////////
    TopRight,

    /////////////////////////////////////////////////
    /// Widget is aligned to the right center.
    /////////////////////////////////////////////////
    RightCenter,

    /////////////////////////////////////////////////
    /// Widget is aligned to the bottom right corner.
    /////////////////////////////////////////////////
    BottomRight,

    /////////////////////////////////////////////////
    /// Widget is aligned to the bottom center.
    /////////////////////////////////////////////////
    BottomCenter,

    /////////////////////////////////////////////////
    /// Widget is aligned to the bottom left corner.
    /////////////////////////////////////////////////
    BottomLeft,

    /////////////////////////////////////////////////
    /// Widget is aligned to the left center.
    /////////////////////////////////////////////////
    LeftCenter,

    /////////////////////////////////////////////////
    /// Widget is aligned to the center.
    /////////////////////////////////////////////////
    Center
  };
} // namespace JourneyOfDreams
