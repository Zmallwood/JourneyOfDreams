#pragma once
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/Size.h"

namespace zw
{
    Size GetCanvasSize();
    float GetAspectRatio();
    std::string FileExtension(const std::string &absPath);
    std::string FilenameNoExtension(const std::string &absPath);
    float ConvertWidthToHeight(float width);
    float ConvertHeightToWidth(float height);
    PointF GetMousePosition();
}
