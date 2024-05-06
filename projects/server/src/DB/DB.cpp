/* Copyright (c) 2024 Andreas Åkerberg. */

#include "DB.h"

// db class implementation.

namespace JourneyOfDreams
{
  DB::DB() {
    std::cout << "Connecting to database..." << std::endl;

    m_parameters = std::make_unique<soci::connection_parameters>(
        "postgresql", "dbname=journeyofdreams user=postgres password=test "
                      "host=host.docker.internal port=5432");
    m_session = std::make_unique<soci::session>();
    m_session->open(*m_parameters);

    std::cout << "Connected to database." << std::endl;
  }

  DB::~DB() {
    m_session->close();
    std::cout << "Connection to database closed." << std::endl;
  }
}