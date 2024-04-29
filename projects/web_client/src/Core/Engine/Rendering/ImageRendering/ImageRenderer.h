#pragma once

#include "Core/Engine/Rendering/RenderingCore/RendererBase.h"

namespace JourneyOfDreams
{
    class ImageRenderer : public RendererBase
    {
      public:
        ImageRenderer();

        ~ImageRenderer();

        RID NewImage();

        /**
         * \brief Draw image to canvas. NOTE: if repeatTexture is true, the image size must be power
         * of 2
         */
        void DrawImage(RID rid, const std::string &imageName, const RectF &dest, bool repeatTexture = false,
                       SizeF textureFillAmount = { 1.0f, 1.0f }, ColorF color = { 1.0f, 1.0f, 1.0f });

        void DrawImage(RID rid, int imageNameHash, const RectF &dest, bool repeatTexture = false,
                       SizeF textureFillAmount = { 1.0f, 1.0f }, ColorF color = { 1.0f, 1.0f, 1.0f });

      private:
        static constexpr int k_locPosition = 0;
        static constexpr int k_locColor = 1;
        static constexpr int k_locUv = 2;
        int m_locNoPixelEffect = -1;
    };
}
