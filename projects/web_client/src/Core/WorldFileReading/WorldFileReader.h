/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* WorldFileReader class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Reads the world data file from the filesystem
  /// and parses the data to create the World and
  /// its WorldAreas.
  /////////////////////////////////////////////////
  class WorldFileReader {
   public:
    /////////////////////////////////////////////////
    /// Read the world file and create the World.
    /////////////////////////////////////////////////
    void ReadWorldFile();

   private:
    const std::string k_worldFileName{"world/World.dat"};
  };
}