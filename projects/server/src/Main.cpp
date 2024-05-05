// Copyright (c) 2024 Andreas Åkerberg.

#include "DB/DB.h"
#include "Net/RunNetServer.h"

int main(int argc, char *argv[]) {
    using namespace journey_of_dreams;
    _<DB>(); // Touch the DB singleton to ensure it is initialized
    RunNetServer();

    return 0;
}
