//  Copyright (C) 2024 Andreas Åkerberg

#include "Object.h"

namespace JourneyOfDreams
{
    Object::Object(const std::string &objectTypeName) : m_type(Hash(objectTypeName))
    {
    }

    Object::Object(int objectTypeHash) : m_type(objectTypeHash)
    {
    }
}