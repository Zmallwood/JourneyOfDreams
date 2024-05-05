// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace JourneyOfDreams {
    class WorldArea;

    class World {
      public:
        World();
        auto WorldArea() {
            return m_worldArea;
        }

      private:
        std::shared_ptr<JourneyOfDreams::WorldArea> m_worldArea;
    };
}