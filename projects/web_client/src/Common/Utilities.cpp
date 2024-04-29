#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

namespace JourneyOfDreams
{
    Size GetCanvasSize()
    {
        int w, h;                                                // To store dimensions in pixels.
        SDL_GetWindowSize(_<Graphics>().Window().get(), &w, &h); // Use SDL to get window size = canvas size.
        return { w, h };
    }

    float GetAspectRatio()
    {
        auto canvasSize = GetCanvasSize();                      // Get canvas dimensions.
        return static_cast<float>(canvasSize.w) / canvasSize.h; // And calculate the ratio between them.
    }

    std::string FileExtension(const std::string &absPath)
    {
        return absPath.substr( // Find last occurrence of '.' and return the part following it.
            absPath.find_last_of('.') + 1);
    }

    std::string FilenameNoExtension(const std::string &absPath)
    {
        auto nameWithExt = absPath.substr( // Find last occurence of '/' and get the part following it.
            absPath.find_last_of('/') + 1);
        return nameWithExt.substr( // Then only keep the part preceeding the last occurrence of '.'.
            0, nameWithExt.find_last_of('.'));
    }

    float ConvertWidthToHeight(float width)
    { // Use aspect ratio to convert from width to corresponding height.
        return width * GetAspectRatio();
    }

    float ConvertHeightToWidth(float height)
    { // Use aspect ratio to convert from height to corresponding width.
        return height / GetAspectRatio();
    }

    PointF GetMousePosition()
    {
        int x, y;                          // To store mouse coordinates in pixels.
        SDL_GetMouseState(&x, &y);         // Use SDL to get current mouse coordinates.
        auto canvasSize = GetCanvasSize(); // Get canvas size.
        return {                           // And use it to convert pixel coordinates to fractal coordinates.
                 static_cast<float>(x) / canvasSize.w, static_cast<float>(y) / canvasSize.h
        };
    }
}
