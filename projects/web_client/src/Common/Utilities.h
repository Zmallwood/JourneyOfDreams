#pragma once
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/Size.h"
#include <string>

namespace zw
{
    class Engine;

    /// Return canvas size in pixels.
    Size GetCanvasSize(Engine& engine);

    /// Get ratio of canvas width/height.
    float GetAspectRatio(Engine& engine);

    /// Get file extension from file path.
    std::string FileExtension(const std::string &absPath);

    /// Get file name without extension from file path.
    std::string FilenameNoExtension(const std::string &absPath);

    /// Convert fractal width to corresponding height.
    float ConvertWidthToHeight(Engine& engine, float width);

    /// Convert fractal height to corresponding width.
    float ConvertHeightToWidth(Engine& engine, float height);

    /// Get mouse position in canvas in pixels.
    PointF GetMousePosition(Engine& engine);
}
