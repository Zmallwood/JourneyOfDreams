// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams {
    class WorldArea;

    class World {
      public:
        World();
        auto WorldArea() {
            return m_worldArea;
        }

      private:
        std::shared_ptr<journey_of_dreams::WorldArea> m_worldArea;
    };
}