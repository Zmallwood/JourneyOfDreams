#include "Utilities.h"

namespace zw
{
    int Hash(const std::string &text)
    {
        return std::hash<std::string>{}(text);
    }
}