// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// object class declaration.

namespace journey_of_dreams
{
  class Object {
   public:
    Object(const std::string &objectTypeName);
    Object(int objectTypeHash);
    auto
    Type() const {
      return m_type;
    }

   private:
    int m_type{0};
  };
} // namespace journey_of_dreams