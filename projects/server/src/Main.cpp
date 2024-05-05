//  Copyright (C) 2024 Andreas Åkerberg

#include "DB/DB.h"
#include "Net/RunNetServer.h"

int main(int argc, char *argv[]) {
    using namespace JourneyOfDreams;
    _<DB>(); // Touch the DB singleton to ensure it is initialized
    RunNetServer();

    return 0;
}
