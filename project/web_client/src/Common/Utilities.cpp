#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

namespace zw
{
	Size GetCanvasSize()
	{
        // To store dimensions
	    int w;
	    int h;

        // Use SDL to get window size = canvas size.
	    SDL_GetWindowSize(_<Graphics>().Window().get(), &w, &h);
	    
	    return { w, h };
	}

	float GetAspectRatio()
	{
        // Get canvas dimensions.
	    auto canvasSize = GetCanvasSize();

        // And calculate the ratio between them.
	    return static_cast<float>(canvasSize.w) / canvasSize.h;
	}

	std::string FileExtension(const std::string &absPath)
	{
        // Find last occurrence of '.' and return the part following it.
	    return absPath.substr(absPath.find_last_of('.') + 1);
	}

	std::string FilenameNoExtension(const std::string &absPath)
	{
        // Find last occurence of '/' and get the part following it.
	    auto nameWithExt = absPath.substr(absPath.find_last_of('/') + 1);

        // Then only keep the part preceeding the last occurrence of '.'.
	    return nameWithExt.substr(0, nameWithExt.find_last_of('.'));
	}

	float ConvertWidthToHeight(float width)
	{
        // Use aspect ratio to convert from width to corresponding height.
	    return width * GetAspectRatio();
	}

	float ConvertHeightToWidth(float height)
	{
        // Use aspect ratio to convert from height to corresponding width.
	    return height / GetAspectRatio();
	}

	PointF GetMousePosition()
	{
        // To store mouse coordinates in pixels.
	    int x;
	    int y;

        // Use SDL to get current mouse coordinates.
	    SDL_GetMouseState(&x, &y);

        // Get canvas size.
	    auto canvasSize = GetCanvasSize();

        // And use it to convert pixel coordinates to fractal coordinates.
	    return { static_cast<float>(x) / canvasSize.w, static_cast<float>(y) / canvasSize.h };
	}
}
