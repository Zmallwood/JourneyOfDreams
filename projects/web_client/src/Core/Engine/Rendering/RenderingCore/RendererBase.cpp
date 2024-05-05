// Copyright (c) 2024 Andreas Åkerberg.

#include "RendererBase.h"
#include "ShaderProgram.h"

// renderer_base class implementation.

namespace journey_of_dreams
{
  RendererBase::RendererBase()
      : m_shaderProgram(std::make_shared<journey_of_dreams::ShaderProgram>()),
        m_VAOIDs(std::make_shared<std::vector<GLuint>>()),
        m_VBOIDs(
            std::make_shared<std::map<
                BufferTypes, std::shared_ptr<std::map<GLuint, GLuint>>>>()) {
  }

  GLuint
  RendererBase::GenNewVAOID() {
    GLuint VAOID;
    glGenVertexArraysOES(1, &VAOID);
    m_VAOIDs->push_back(VAOID); // Store newly created VAO id

    return VAOID;
  }

  GLuint
  RendererBase::GenNewBuffID(BufferTypes buffType, GLuint VAOID) {
    GLuint buffID;
    glGenBuffers(1, &buffID);
    if (!m_VBOIDs->contains(buffType)) {
      m_VBOIDs->insert(
          {buffType, std::make_shared<std::map<GLuint, GLuint>>()});
    }
    (*(*m_VBOIDs)[buffType])[VAOID] = buffID; // Store newly created VBO id,
                                              // with the VAO id as one of keys
    return buffID;
  }

  void
  RendererBase::SetIndicesData(GLuint indicesVBOID, int numIndices,
                               const void *data) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, // Bind the VBO buffer that should
                                          // hold indices data
                 indicesVBOID);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, // Set indices data as element array buffer
        numIndices * k_numFloatsPerEntry.at(BufferTypes::Indices) *
            sizeof(float),
        data, GL_DYNAMIC_DRAW);
  }

  void
  RendererBase::SetData(GLuint VBOID, int numEntries, const void *data,
                        BufferTypes buffType, int layoutLocation) const {
    if (buffType == BufferTypes::BoneIDs) {
      SetArrayBufferDataInt(
          VBOID, // Call other method for BoneIDs than other buffer types
          numEntries, data, k_numFloatsPerEntry.at(buffType), layoutLocation);
    } else {
      SetArrayBufferData(
          VBOID, // Call this function for all buffer types except BoneIDs
          numEntries, data, k_numFloatsPerEntry.at(buffType), layoutLocation);
    }
  }

  void
  RendererBase::SetArrayBufferData(GLuint VBOID, int numEntries,
                                   const void *data, int numFloatsPerEntry,
                                   int layoutLocation) const {
    glBindBuffer(GL_ARRAY_BUFFER,
                 VBOID);          // Bind the VBO for the provided VBO id
    glBufferData(GL_ARRAY_BUFFER, // Set the buffer data as an array buffer
                 numEntries * numFloatsPerEntry * sizeof(float), data,
                 GL_DYNAMIC_DRAW);

    if (layoutLocation >= 0) // Is valid layout location?
    {
      glVertexAttribPointer( // Configure layout float float values
          layoutLocation, numFloatsPerEntry, GL_FLOAT, GL_FALSE, 0,
          (const GLvoid *)0);
      glEnableVertexAttribArray( // Enable layout
          layoutLocation);
    }
  }

  void
  RendererBase::SetArrayBufferDataInt(GLuint VBOID, int numEntries,
                                      const void *data, int numFloatsPerEntry,
                                      int layoutLocation) const {
    glBindBuffer(GL_ARRAY_BUFFER,
                 VBOID);          // Bind the VBO for the provided VBO id
    glBufferData(GL_ARRAY_BUFFER, // Set the buffer data as an array buffer
                 numEntries * numFloatsPerEntry * sizeof(int), data,
                 GL_DYNAMIC_DRAW);

    if (layoutLocation >= 0) // Is valid layout location?
    {
      glEnableVertexAttribArray(3); // Enable generic vertex attribute
      // glVertexAttribIPointer(       // Configure layout for int values
      //     layoutLocation, numFloatsPerEntry, GL_INT, 0, (const GLvoid *)0);
      glVertexAttribPointer( // Configure layout for float values
          layoutLocation, numFloatsPerEntry, GL_INT, GL_FALSE, 0,
          (const GLvoid *)0);
      glEnableVertexAttribArray( // Enable layout
          layoutLocation);
    }
  }

  GLuint
  RendererBase::GetUniformLocation(const std::string &variableName) {
    return glGetUniformLocation( // Get layout location of uniform variable in
                                 // the shader
        m_shaderProgram->ProgramID(), variableName.c_str());
  }

  void
  RendererBase::UseVAOBegin(GLuint VAOID) const {
    glUseProgram(
        m_shaderProgram
            ->ProgramID()); // Start using shader  program and provided VAO
    glBindVertexArrayOES(VAOID);
  }

  GLuint
  RendererBase::GetBuffID(BufferTypes buffType, GLuint VAOID) const {
    return m_VBOIDs->at(buffType)->at(
        VAOID); // Returns the buffer of provided type and VAO id
  }

  void
  RendererBase::UpdateIndicesData(GLuint indicesVBOID,
                                  std::vector<int> &indices) const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, // Bind VBO with provided id, being an
                                          // element array buffer
                 indicesVBOID);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, // Set the buffer data
                    0, sizeof(float) * indices.size(), indices.data());
  }

  void
  RendererBase::UpdateArrayBufferData(GLuint VBOID, std::vector<float> &data,
                                      int numFloatsPerEntry,
                                      int layoutLocation) const {
    glBindBuffer(GL_ARRAY_BUFFER,
                 VBOID); // Bind VBO with provided id, being an array buffer
    glBufferSubData(GL_ARRAY_BUFFER, // Set the buffer data
                    0, sizeof(float) * data.size(), data.data());
    glVertexAttribPointer(layoutLocation, numFloatsPerEntry, GL_FLOAT, GL_FALSE,
                          0, (const GLvoid *)0);
    glEnableVertexAttribArray(layoutLocation); // Enable layout
  }

  void
  RendererBase::UpdateArrayBufferDataInt(GLuint VBOID, std::vector<float> &data,
                                         int numFloatsPerEntry,
                                         int layoutLocation) const {
    glBindBuffer(GL_ARRAY_BUFFER,
                 VBOID); // Bind VBO with provided id, being an array buffer
    glBufferSubData(GL_ARRAY_BUFFER, // Set the buffer data
                    0, sizeof(int) * data.size(), data.data());
    // glVertexAttribIPointer(layoutLocation, // Configure layout for int values
    // numFloatsPerEntry, GL_INT, 0, (const GLvoid *)0);
    glVertexAttribPointer(layoutLocation, numFloatsPerEntry, GL_INT, GL_FALSE,
                          0, (const GLvoid *)0);
    glEnableVertexAttribArray(layoutLocation); // Enable layout
  }

  void
  RendererBase::UpdateData(GLuint VBOID, std::vector<float> &data,
                           BufferTypes buffType, int layoutLocation) const {
    if (buffType == BufferTypes::BoneIDs) // Does the buffer hold BoneID data=
    {
      UpdateArrayBufferDataInt(VBOID, // If so, update buffer with int data
                               data, k_numFloatsPerEntry.at(buffType),
                               layoutLocation);
    } else {
      UpdateArrayBufferData(VBOID, // Else, update with float data
                            data, k_numFloatsPerEntry.at(buffType),
                            layoutLocation);
    }
  }

  void
  RendererBase::UseVAOEnd() const {
    glBindVertexArrayOES(0); // Unbind currently used VAO
    glUseProgram(0);         // Stop using shader program
  }

  void
  RendererBase::CleanupBase() const {
    for (auto &buffType : *m_VBOIDs) // Loop through all keys of buffer types
    {
      for (auto &bufferEntry :
           (*buffType.second)) // Loop through all keys of VAO ids
      {
        glDeleteBuffers(1, // Delete every VBO
                        &bufferEntry.second);
      }
    }

    for (auto VAOID : *m_VAOIDs) // Loop through all VAO ids
    {
      glDeleteVertexArraysOES(1, &VAOID); // And delete them
    }

    m_shaderProgram->Cleanup(); // Finally, clean up shader proram
  }

  std::shared_ptr<journey_of_dreams::ShaderProgram>
  RendererBase::ShaderProgram() {
    return m_shaderProgram;
  }

  const int
  RendererBase::NumVerticesInRectangle() {
    return k_numVerticesInRectangle;
  }
} // namespace journey_of_dreams