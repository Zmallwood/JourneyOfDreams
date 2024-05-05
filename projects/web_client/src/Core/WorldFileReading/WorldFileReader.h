// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

namespace journey_of_dreams {
    class WorldFileReader {
      public:
        void ReadWorldFile();

      private:
        const std::string k_worldFileName{ "world/World.dat" };
    };
}