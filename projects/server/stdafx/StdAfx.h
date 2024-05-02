//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <thread>

#include <asio/io_service.hpp>

#include "../../shared/common/src/Singleton.h"

#include <soci/soci.h>
#include <soci/postgresql/soci-postgresql.h>