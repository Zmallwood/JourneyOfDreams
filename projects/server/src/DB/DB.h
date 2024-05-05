// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// db class declaration.

namespace journey_of_dreams
{
  class DB {
   public:
    DB();
    ~DB();

   private:
    std::unique_ptr<soci::session> m_session;
    std::unique_ptr<soci::connection_parameters> m_parameters;
  };
} // namespace journey_of_dreams