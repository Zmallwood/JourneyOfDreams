#pragma once

#include "Core/Engine/Rendering/RenderingCore/RendererBase.h"

namespace zw
{
    class ImageRenderer : public RendererBase
    {
      public:
        ImageRenderer();
        ~ImageRenderer();
        RID NewImage();
        void DrawImage(RID rid, const std::string& imageName, const RectF &dest, ColorF color);

      private:
        static constexpr int k_locPosition = 0;
        static constexpr int k_locColor = 1;
        static constexpr int k_locUv = 2;
        int m_locNoPixelEffect = -1;
    };
}