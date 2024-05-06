/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

// singleton function implementation.

namespace JourneyOfDreams
{
  template <class T>
  auto &_() {
    static T instance;
    return instance;
  }
}