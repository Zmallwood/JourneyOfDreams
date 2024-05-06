/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

// global_properties class declaration.

namespace JourneyOfDreams
{
  class GlobalProperties {
   public:
    auto WorldAreaSize() {
      return m_worldAreaSize;
    }

   private:
    Size m_worldAreaSize{100, 100};
  };
}