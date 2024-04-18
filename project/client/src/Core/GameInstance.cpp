#include "GameInstance.h"
#include "Engine/Graphics/Graphics.h"
#include "Engine/Rendering/Shaders/DefaultShaderFragment.h"
#include "Engine/Rendering/Shaders/DefaultShaderVertex.h"
#include "Engine/Net/Net.h"

namespace zw
{
    struct context
    {
        int x;
    };

    void loop_fn(void *arg)
    {
        _<Graphics>().ClearCanvas();

        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);

        _<Graphics>().PresentCanvas();
    }

    void GameInstance::Run()
    {
        _<Net>();

        _<Graphics>();

        struct context ctx;
        int simulate_infinite_loop = 1;

        ctx.x = 0;

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

        emscripten_set_main_loop_arg(loop_fn, &ctx, -1, simulate_infinite_loop);
    }
}