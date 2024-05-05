// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams {
    class GlobalProperties {
      public:
        auto WorldAreaSize() {
            return m_worldAreaSize;
        }

      private:
        Size m_worldAreaSize{ 100, 100 };
    };
}