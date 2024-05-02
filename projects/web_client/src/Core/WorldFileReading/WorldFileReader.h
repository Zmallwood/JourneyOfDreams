//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    class WorldFileReader
    {
      public:
        void ReadWorldFile();

      private:
        const std::string k_worldFileName{ "world/World.dat" };
    };
}