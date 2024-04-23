#include "Generation/GenerateNewWorld.h"
#include "Saving/SaveWorldToFile.h"

int main(int argc, char *argv[])
{
    using namespace zw;

    std::cout << "Journey Of Dreams - World Generator\n";

    SaveWorldToFile(GenerateNewWorld());

    return 0;
}
