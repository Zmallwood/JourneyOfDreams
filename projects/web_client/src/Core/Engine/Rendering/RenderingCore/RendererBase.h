/* Copyright (c) 2024 Andreas Åkerberg. */

#pragma once

#include "BufferTypes.h"

/* RendererBase class declaration. */

namespace JourneyOfDreams
{
  class ShaderProgram;

  /////////////////////////////////////////////////
  /// Base class for all renderers which manages shader program,
  /// VAOs and VBOs.
  /////////////////////////////////////////////////
  class RendererBase {
   protected:
    /////////////////////////////////////////////////
    /// Create shader program and storages for VAOs and VBOs.
    /////////////////////////////////////////////////
    RendererBase();

    /////////////////////////////////////////////////
    /// Generate new VAO ID, add it to storage and return it.
    ///
    /// @return The new VAO ID.
    /////////////////////////////////////////////////
    GLuint GenNewVAOID();

    /////////////////////////////////////////////////
    /// Generate new buffer ID, add it to storage and return it.
    ///
    /// @param buffType The type of buffer.
    /// @param VAOID The VAO ID to associate with the buffer.
    /// @return The new buffer ID.
    /////////////////////////////////////////////////
    GLuint GenNewBuffID(BufferTypes buffType, GLuint VAOID);

    /////////////////////////////////////////////////
    /// Set indices data for a VBO with provided ID.
    ///
    /// @param indicesVBOID The ID of the VBO.
    /// @param numIndices The number of indices.
    /// @param data The data to set.
    /////////////////////////////////////////////////
    void SetIndicesData(GLuint indicesVBOID, int numIndices,
                        const void *data) const;

    /////////////////////////////////////////////////
    /// Set data, other than indices, for a VBO with provided ID.
    ///
    /// @param VBOID The ID of the VBO.
    /// @param numEntries The number of entries.
    /// @param data The data to set.
    /// @param buffType The type of buffer.
    /// @param layoutLocation The layout location if
    ///                       need to specify explicitly.
    /////////////////////////////////////////////////
    void SetData(GLuint VBOID, int numEntries, const void *data,
                 BufferTypes buffType, int layoutLocation = -1) const;

    /////////////////////////////////////////////////
    /// Get uniform location for a variable in shader program.
    ///
    /// @param variableName The name of the variable.
    /// @return The uniform location in the shader program.
    /////////////////////////////////////////////////
    GLuint GetUniformLocation(const std::string &variableName);

    /////////////////////////////////////////////////
    /// Start use shader progrma and VAO with provided ID.
    ///
    /// @param VAOID The ID of the VAO.
    /////////////////////////////////////////////////
    void UseVAOBegin(GLuint VAOID) const;

    /////////////////////////////////////////////////
    /// Get buffer ID for a VBO with provided type and
    /// which belongs to VAO with provided ID.
    ///
    /// @param buffType The type of buffer.
    /// @param VAOID The ID of the VAO to which the buffer belongs.
    /// @return The buffer ID.
    /////////////////////////////////////////////////
    GLuint GetBuffID(BufferTypes buffType, GLuint VAOID) const;

    /////////////////////////////////////////////////
    /// Update indices data for a VBO with provided ID.
    ///
    /// @param indicesVBOID The ID of the VBO.
    /// @param indices The indices data to update.
    /////////////////////////////////////////////////
    void UpdateIndicesData(GLuint indicesVBOID,
                           std::vector<int> &indices) const;

    /////////////////////////////////////////////////
    /// Update data, other than indices, for a VBO with provided ID.
    ///
    /// @param VBOID The ID of the VBO.
    /// @param data The data to update.
    /// @param buffType The type of buffer.
    /// @param layoutLocation The layout location of
    ///                       the data in the shader program.
    /////////////////////////////////////////////////
    void UpdateData(GLuint VBOID, std::vector<float> &data,
                    BufferTypes buffType, int layoutLocation) const;

    /////////////////////////////////////////////////
    /// Stop using current VAO and shader program.
    /////////////////////////////////////////////////
    void UseVAOEnd() const;

    /////////////////////////////////////////////////
    /// Delete all VAOs and VBOs and cleanup shader program.
    /////////////////////////////////////////////////
    void CleanupBase() const;

    /////////////////////////////////////////////////
    /// Get shader program.
    ///
    /// @return The shader program.
    /////////////////////////////////////////////////
    std::shared_ptr<JourneyOfDreams::ShaderProgram> ShaderProgram();

    /////////////////////////////////////////////////
    /// Get number of vertices in a rectangle.
    ///
    /// @return The number of vertices in a rectangle (4).
    /////////////////////////////////////////////////
    static const int NumVerticesInRectangle();

   private:
    void SetArrayBufferData(GLuint VBOID, int numEntries, const void *data,
                            int numFloatsPerEntry,
                            int layoutLocation = -1) const;
    void SetArrayBufferDataInt(GLuint VBOID, int numEntries, const void *data,
                               int numFloatsPerEntry,
                               int layoutLocation = -1) const;
    void UpdateArrayBufferData(GLuint VBOID, std::vector<float> &data,
                               int numFloatsPerEntry, int layoutLocation) const;
    void UpdateArrayBufferDataInt(GLuint VBOID, std::vector<float> &data,
                                  int numFloatsPerEntry,
                                  int layoutLocation) const;

    std::shared_ptr<std::vector<GLuint>> m_VAOIDs;
    std::shared_ptr<
        std::map<BufferTypes, std::shared_ptr<std::map<GLuint, GLuint>>>>
        m_VBOIDs;
    std::shared_ptr<JourneyOfDreams::ShaderProgram> m_shaderProgram;
    inline static const auto k_numFloatsPerEntry = std::map<BufferTypes, int>{
        {BufferTypes::Indices, 1},     {BufferTypes::Positions2D, 2},
        {BufferTypes::Positions3D, 3}, {BufferTypes::Colors, 4},
        {BufferTypes::UVs, 2},         {BufferTypes::Normals, 3},
        {BufferTypes::BoneIDs, 4},     {BufferTypes::Weights, 4}};
    inline static const int k_numVerticesInRectangle{4};
  };
}