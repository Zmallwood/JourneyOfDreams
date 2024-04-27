#include "Object.h"

namespace zw
{
    Object::Object(const std::string &objectTypeName) : m_type(Hash(objectTypeName))
    {
    }

    Object::Object(int objectTypeHash) : m_type(objectTypeHash)
    {
    }
}