#include "Utilities.h"

namespace zw
{
    int Hash(const std::string &text)
    {
        return std::hash<std::string>{}(text);
    }

    std::string FileExtension(const std::string &absPath)
    {
        return absPath.substr(absPath.find_last_of('.') + 1);
    }

    std::string FilenameNoExtension(const std::string &absPath)
    {
        auto nameWithExt = absPath.substr(absPath.find_last_of('/') + 1);

        return nameWithExt.substr(0, nameWithExt.find_last_of('.'));
    }
}