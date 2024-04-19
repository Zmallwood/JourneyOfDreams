#pragma once

namespace zw
{
    int Hash(const std::string &text);
    std::string FileExtension(const std::string &absPath);
    std::string FilenameNoExtension(const std::string &absPath);
}