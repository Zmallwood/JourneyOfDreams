#pragma once

namespace zw
{
    class WorldFileReader
    {
      public:
        void ReadWorldFile();

      private:
        const std::string k_worldFileName{ "world/World.dat" };
    };
}