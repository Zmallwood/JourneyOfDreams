#include "Utilities.h"
#include "Core/Engine/Graphics/Graphics.h"

namespace zw
{
    int Hash(const std::string &text)
    {
        return std::hash<std::string>{}(text);
    }

    Size GetCanvasSize()
    {
        int w, h;
        SDL_GetWindowSize(_<Graphics>().Window().get(), &w, &h);

        return { w, h };
    }

    float GetAspectRatio()
    {
        auto canvSz = GetCanvasSize();

        return static_cast<float>(canvSz.w) / canvSz.h;
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

    float ConvertWidthToHeight(float width)
    {
        return width * GetAspectRatio();
    }

    float ConvertHeightToWidth(float height)
    {
        return height / GetAspectRatio();
    }
}