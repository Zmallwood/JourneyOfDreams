//  Copyright (C) 2024 Andreas Åkerberg

#pragma once

namespace JourneyOfDreams
{
    /////////////////////////////////////////////////
    /// Represents a shader program with a vertex and fragment shader.
    /////////////////////////////////////////////////
    class ShaderProgram
    {
      public:
        /////////////////////////////////////////////////
        /// Compile the vertex and fragment shaders and link them into a program.
        ///
        /// \param vertexShaderSource The source code of the vertex shader.
        /// \param fragmentShaderSource The source code of the fragment shader.
        /// \return True if the shader program was created successfully.
        /////////////////////////////////////////////////
        bool Create(const GLchar *vertexShaderSource, const GLchar *fragmentShaderSource);

        /////////////////////////////////////////////////
        /// Delete the shader program.
        /////////////////////////////////////////////////
        void Cleanup();

        /////////////////////////////////////////////////
        /// Get the shader program ID.
        ///
        /// \return The shader program ID.
        /////////////////////////////////////////////////
        GLuint ProgramID();

      private:
        GLuint CompileShader(const GLchar *shaderSource, GLuint *shader, GLenum shaderType);
        GLuint m_programID {0};
    };
}
