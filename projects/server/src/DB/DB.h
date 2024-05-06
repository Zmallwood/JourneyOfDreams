/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

/* DB class declaration. */

namespace JourneyOfDreams
{
  class DB {
   public:
    DB();
    ~DB();

   private:
    std::unique_ptr<soci::session> m_session;
    std::unique_ptr<soci::connection_parameters> m_parameters;
  };
}