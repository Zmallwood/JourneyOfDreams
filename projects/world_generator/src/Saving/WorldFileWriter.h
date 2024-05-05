// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// world_file_writer class declaration.

namespace journey_of_dreams
{
  class WorldFileWriter {
   public:
    void WriteWorldToFile();

   private:
    const std::string k_worldFileName{"World.dat"};
  };
} // namespace journey_of_dreams