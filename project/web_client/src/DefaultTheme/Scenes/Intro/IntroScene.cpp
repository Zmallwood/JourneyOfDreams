#include "IntroScene.h"
#include "Core/Engine/Input/KeyboardInput.h"
#include "Core/Engine/Rendering/Shaders/DefaultShaderFragment.h"
#include "Core/Engine/Rendering/Shaders/DefaultShaderVertex.h"
#include "Core/Engine/ScenesCore/SceneManager.h"

namespace zw
{
    IntroScene::IntroScene()
    {
        // Create Vertex Array Object
        GLuint vao;
        glGenVertexArraysOES(1, &vao);
        glBindVertexArrayOES(vao);

        // Create a Vertex Buffer Object and copy the vertex data to it
        GLuint vbo;
        glGenBuffers(1, &vbo);

        GLfloat vertices[] = { 0.0f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f };

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // Create and compile the vertex shader
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);

        // Create and compile the fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);

        // Link the vertex and fragment shader into a shader program
        GLuint shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        // glBindFragDataLocation(shaderProgram, 0, "outColor");
        glLinkProgram(shaderProgram);
        glUseProgram(shaderProgram);

        // Specify the layout of the vertex data
        GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
        glEnableVertexAttribArray(posAttrib);
        glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
    }

    void IntroScene::UpdateDerived()
    {
        if (_<KeyboardInput>().AnyKeyIsPressed())
            _<SceneManager>().GoToScene("MainMenuScene");
    }

    void IntroScene::RenderDerived()
    {
        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}