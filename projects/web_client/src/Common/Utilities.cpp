#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

namespace JourneyOfDreams
{
    Size GetCanvasSize()
    {
        //
        // To store dimensions in pixels.
        //
        int w;
        int h;

        //
        // Use SDL to get window size = canvas size.
        //
        SDL_GetWindowSize(_<Graphics>().Window().get(), &w, &h);

        return { w, h };
    }

    float GetAspectRatio()
    {
        //
        // Get canvas dimensions.
        //
        auto canvasSize = GetCanvasSize();

        //
        // And calculate the ratio between them.
        //
        auto aspectRatio = static_cast<float>(canvasSize.w) / canvasSize.h;

        return aspectRatio;
    }

    std::string FileExtension(const std::string &absPath)
    {
        //
        // Find last occurrence of '.' and keep the part following it.
        //
        auto extension = absPath.substr(absPath.find_last_of('.') + 1);

        return extension;
    }

    std::string FilenameNoExtension(const std::string &absPath)
    {
        //
        // Find last occurence of '/' and get the part following it.
        //
        auto nameWithExt = absPath.substr(absPath.find_last_of('/') + 1);

        //
        // Then only keep the part preceeding the last occurrence of '.'.
        //
        auto fileName = nameWithExt.substr(0, nameWithExt.find_last_of('.'));

        return fileName;
    }

    float ConvertWidthToHeight(float width)
    {
        //
        // Use aspect ratio to convert from width to corresponding height.
        //
        return width * GetAspectRatio();
    }

    float ConvertHeightToWidth(float height)
    {
        //
        // Use aspect ratio to convert from height to corresponding width.
        //
        return height / GetAspectRatio();
    }

    PointF GetMousePosition()
    {
        //
        // To store mouse coordinates in pixels.
        //
        int x;
        int y;

        //
        // Use SDL to get current mouse coordinates.
        //
        SDL_GetMouseState(&x, &y);

        //
        // Get canvas size.
        //
        auto canvasSize = GetCanvasSize();

        //
        // And use it to convert pixel coordinates to fractal coordinates.
        //
        auto mousePosition
            = PointF{ static_cast<float>(x) / canvasSize.w, static_cast<float>(y) / canvasSize.h };

        return mousePosition;
    }
}
