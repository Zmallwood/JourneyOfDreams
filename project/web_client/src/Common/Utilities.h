#pragma once

#include "../../shared/matter/src/Size.h"

namespace zw
{
    int Hash(const std::string &text);
    Size GetCanvasSize();
    float GetAspectRatio();
    std::string FileExtension(const std::string &absPath);
    std::string FilenameNoExtension(const std::string &absPath);
    float ConvertWidthToHeight(float width);
    float ConvertHeightToWidth(float height);
}