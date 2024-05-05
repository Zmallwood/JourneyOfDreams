//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams {
    class WorldFileWriter {
      public:
        void WriteWorldToFile();

      private:
        const std::string k_worldFileName{ "World.dat" };
    };
}