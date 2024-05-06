/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* Singleton function implementation. */

namespace JourneyOfDreams
{
  template <class T>
  auto &_() {
    static T instance;
    return instance;
  }
}