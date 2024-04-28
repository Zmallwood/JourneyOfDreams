#pragma once
#include "../../shared/matter/src/PointF.h"
#include "../../shared/matter/src/Size.h"
#include <string>

namespace zw
{
    class Engine;

    /// Return canvas size in pixels.
    inline Size GetCanvasSize(Engine& engine);

    /// Get ratio of canvas width/height.
    inline float GetAspectRatio(Engine& engine);

    /// Get file extension from file path.
    inline std::string FileExtension(const std::string &absPath);

    /// Get file name without extension from file path.
    inline std::string FilenameNoExtension(const std::string &absPath);

    /// Convert fractal width to corresponding height.
    inline float ConvertWidthToHeight(Engine& engine, float width);

    /// Convert fractal height to corresponding width.
    inline float ConvertHeightToWidth(Engine& engine, float height);

    /// Get mouse position in canvas in pixels.
    inline PointF GetMousePosition(Engine& engine);
}
