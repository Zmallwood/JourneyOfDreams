/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Object.h"

/* Object class implementation. */

namespace JourneyOfDreams
{
  Object::Object(const std::string &objectTypeName)
      : m_type(Hash(objectTypeName)) {
  }

  Object::Object(int objectTypeHash)
      : m_type(objectTypeHash) {
  }

  int Object::Type() const {
    return m_type;
  }
}