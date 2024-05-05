// Copyright (c) 2024 Andreas Åkerberg.

#include "Object.h"

// object class implementation.

namespace journey_of_dreams
{
  Object::Object(const std::string &objectTypeName)
      : m_type(Hash(objectTypeName)) {
  }

  Object::Object(int objectTypeHash) : m_type(objectTypeHash) {
  }
} // namespace journey_of_dreams