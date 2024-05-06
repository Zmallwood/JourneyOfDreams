/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once
#include "Core/Engine/Rendering/RenderingCore/RendererBase.h"

// image_renderer class declaration.

namespace JourneyOfDreams
{
  /////////////////////////////////////////////////
  /// Allocates resources for, and renders images.
  /////////////////////////////////////////////////
  class ImageRenderer : public RendererBase {
   public:
    /////////////////////////////////////////////////
    /// Initialize shader.
    /////////////////////////////////////////////////
    ImageRenderer();

    /////////////////////////////////////////////////
    /// Call base class cleanup.
    /////////////////////////////////////////////////
    ~ImageRenderer();

    /////////////////////////////////////////////////
    /// Allocates resources for a new image and returns the ID.
    ///
    /// \return The image ID.
    /////////////////////////////////////////////////
    RID NewImage();

    /////////////////////////////////////////////////
    /// Draw image to canvas. NOTE: if repeatTexture
    /// is true, the image size must be power of 2.
    ///
    /// \param rid The image ID.
    /// \param imageName The image name.
    /// \param dest The destination rectangle.
    /// \param repeatTexture If the texture should repeat.
    /// \param textureFillAmount The amount to fill the texture.
    /// \param color The color to draw the image.
    /////////////////////////////////////////////////
    void DrawImage(RID rid, const std::string &imageName, const RectF &dest,
                   bool repeatTexture = false,
                   SizeF textureFillAmount = {1.0f, 1.0f},
                   ColorF color = {1.0f, 1.0f, 1.0f});

    /////////////////////////////////////////////////
    /// Draw image to canvas. NOTE: if repeatTexture
    /// is true, the image size must be power of 2.
    ///
    /// \param rid The image ID.
    /// \param imageNameHash The image name hash.
    /// \param dest The destination rectangle.
    /// \param repeatTexture If the texture should repeat.
    /// \param textureFillAmount The amount to fill the texture.
    /// \param color The color to draw the image.
    /////////////////////////////////////////////////
    void DrawImage(RID rid, int imageNameHash, const RectF &dest,
                   bool repeatTexture = false,
                   SizeF textureFillAmount = {1.0f, 1.0f},
                   ColorF color = {1.0f, 1.0f, 1.0f});

   private:
    static constexpr int k_locPosition = 0;
    static constexpr int k_locColor = 1;
    static constexpr int k_locUv = 2;
    int m_locNoPixelEffect = -1;
  };
}