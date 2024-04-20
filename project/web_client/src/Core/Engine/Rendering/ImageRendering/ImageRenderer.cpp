#include "ImageRenderer.h"
#include "Core/Engine/Assets/ImageBank.h"
#include "Core/Engine/Rendering/RenderingCore/ShaderProgram.h"
#include "Shader/DefaultShaderImagesFragment.h"
#include "Shader/DefaultShaderImagesVertex.h"

namespace zw
{
    ImageRenderer::ImageRenderer()
    {
        ShaderProgram()->Create(defaultShaderImagesVertex, defaultShaderImagesFragment);
        // m_locNoPixelEffect = GetUniformLocation("noPixelEffect");
    }

    ImageRenderer::~ImageRenderer()
    {
        CleanupBase();
    }

    RID ImageRenderer::NewImage()
    {
        auto rid = GenNewVAOID();
        UseVAOBegin(rid);
        auto indexBuffID = GenNewBuffID(BufferTypes::Indices, rid);
        auto posBuffID = GenNewBuffID(BufferTypes::Positions2D, rid);
        auto colorBuffID = GenNewBuffID(BufferTypes::Colors, rid);
        auto uvBuffID = GenNewBuffID(BufferTypes::Uvs, rid);
        SetIndicesData(indexBuffID, RendererBase::k_numVertsInRect, nullptr);
        SetData(posBuffID, RendererBase::k_numVertsInRect, nullptr, BufferTypes::Positions2D);
        SetData(colorBuffID, RendererBase::k_numVertsInRect, nullptr, BufferTypes::Colors);
        SetData(uvBuffID, RendererBase::k_numVertsInRect, nullptr, BufferTypes::Uvs);
        UseVAOEnd();

        return rid;
    }

    void ImageRenderer::DrawImage(RID rid, const std::string &imageName, const RectF &dest, ColorF color)
    {
        auto GLRect = dest.ToGLRectF();
        Vertex2F verts[RendererBase::k_numVertsInRect];
        verts[0].pos = { GLRect.x, GLRect.y - GLRect.h };
        verts[1].pos = { GLRect.x, GLRect.y };
        verts[2].pos = { GLRect.x + GLRect.w, GLRect.y };
        verts[3].pos = { GLRect.x + GLRect.w, GLRect.y - GLRect.h };
        verts[0].uv = { 0.0f, 1.0f };
        verts[1].uv = { 0.0f, 0.0f };
        verts[2].uv = { 1.0f, 0.0f };
        verts[3].uv = { 1.0f, 1.0f };
        glDisable(GL_DEPTH_TEST);
        auto imageID = _<ImageBank>().GetImage(imageName);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_2D, imageID);
        auto indices = std::vector<int>(RendererBase::k_numVertsInRect);
        std::iota(std::begin(indices), std::end(indices), 0);
        std::vector<float> positions;
        std::vector<float> colors;
        std::vector<float> uvs;
        for (auto &vert : verts)
        {
            positions.push_back(vert.pos.x);
            positions.push_back(vert.pos.y);
            colors.push_back(color.r);
            colors.push_back(color.g);
            colors.push_back(color.b);
            colors.push_back(color.a);
            uvs.push_back(vert.uv.x);
            uvs.push_back(vert.uv.y);
        }

        UseVAOBegin(rid);
        auto noPixelEffect = true;
        // glUniform1f(m_locNoPixelEffect, noPixelEffect ? 1.0f : 0.0f);
        auto indexBuffID = GetBuffID(BufferTypes::Indices, rid);
        auto posBuffID = GetBuffID(BufferTypes::Positions2D, rid);
        auto colorBuffID = GetBuffID(BufferTypes::Colors, rid);
        auto uvBuffID = GetBuffID(BufferTypes::Uvs, rid);
        UpdateIndicesData(indexBuffID, indices);
        UpdateData(posBuffID, positions, BufferTypes::Positions2D, k_locPosition);
        UpdateData(colorBuffID, colors, BufferTypes::Colors, k_locColor);
        UpdateData(uvBuffID, uvs, BufferTypes::Uvs, k_locUv);
        glDrawElements(GL_TRIANGLE_FAN, RendererBase::k_numVertsInRect, GL_UNSIGNED_INT, NULL);
        UseVAOEnd();
    }
}