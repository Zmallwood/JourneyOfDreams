/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* BufferTypes enum class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// The different types of buffers that can be created.
  /////////////////////////////////////////////////
  enum class BufferTypes {
    /////////////////////////////////////////////////
    /// The buffer contains indices.
    /////////////////////////////////////////////////
    Indices,

    /////////////////////////////////////////////////
    /// The buffer contains positions in 2D coordinates.
    /////////////////////////////////////////////////
    Positions2D,

    /////////////////////////////////////////////////
    /// The buffer contains positions in 3D coordinates.
    /////////////////////////////////////////////////
    Positions3D,

    /////////////////////////////////////////////////
    /// The buffer contains colors.
    /////////////////////////////////////////////////
    Colors,

    /////////////////////////////////////////////////
    /// The buffer contains texture coordinates.
    /////////////////////////////////////////////////
    UVs,

    /////////////////////////////////////////////////
    /// The buffer contains normals.
    /////////////////////////////////////////////////
    Normals,

    /////////////////////////////////////////////////
    /// The buffer contains IDs of bones used for skeleton animation.
    /////////////////////////////////////////////////
    BoneIDs,

    /////////////////////////////////////////////////
    /// The buffer contains weights of bones used for skeleton animation.
    /////////////////////////////////////////////////
    Weights,

    /////////////////////////////////////////////////
    /// The buffer contains misc data.
    /////////////////////////////////////////////////
    Misc
  };
}