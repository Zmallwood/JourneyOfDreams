/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Generation/GenerateNewWorld.h"
#include "Saving/WorldFileWriter.h"

// main function implementation.

int main(int argc, char *argv[]) {
  using namespace JourneyOfDreams;

  std::cout << "Journey Of Dreams - World Generator\n";

  GenerateNewWorld();
  _<WorldFileWriter>().WriteWorldToFile();

  return 0;
}
