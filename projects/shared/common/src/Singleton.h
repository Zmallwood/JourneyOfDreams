// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// singleton function implementation.

namespace journey_of_dreams
{
  template <class T>
  auto &
  _() {
    static T instance;
    return instance;
  }
} // namespace journey_of_dreams