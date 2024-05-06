/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* WorldFileWriter class declaration. */

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  ///
  /////////////////////////////////////////////////
  class WorldFileWriter {
   public:
    /////////////////////////////////////////////////
    ///
    /////////////////////////////////////////////////
    void WriteWorldToFile();

   private:
    const std::string k_worldFileName{"World.dat"};
  };
}