/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* Precompiled headers for Server. */

#include <algorithm>
#include <functional>
#include <iostream>
#include <thread>

#include <asio/io_service.hpp>

#include "../../shared/common/src/Singleton.h"

#include <soci/postgresql/soci-postgresql.h>
#include <soci/soci.h>