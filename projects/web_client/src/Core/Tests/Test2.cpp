// Copyright (c) 2024 Andreas Åkerberg.

#include "Test2.h"
#include "Core/Engine/Assets/ImageBank.h"

namespace journey_of_dreams {
    static const char *vertexShaderSource = "#version 300 es\n"
                                            "layout (location = 0) in vec3 aPos;\n"
                                            "out float u;\n"
                                            "out float v;\n"
                                            "void main()\n"
                                            "{\n"
                                            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                            "   u = aPos.x;\n"
                                            "   v = aPos.y;\n"
                                            "}\0";
    static const char *fragmentShaderSource = "#version 300 es\n"
                                              "precision mediump float;\n"
                                              "in float u;\n"
                                              "in float v;\n"
                                              "out vec4 FragColor;\n"
                                              "uniform sampler2D TexUnit;\n"
                                              "void main() {\n"
                                              "    FragColor = texture(TexUnit, vec2(u,v));\n"
                                              "}\0";
    static GLFWwindow *window;
    static GLuint maxitersLocation;

    Test2::Test2() {
        SDL_Init(SDL_INIT_EVERYTHING);
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        window = glfwCreateWindow(400, 300, "The Window Title", NULL, NULL);
        glfwMakeContextCurrent(window);

        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        GLchar infoLog[256];
        glGetShaderInfoLog(vertexShader, 256, NULL, infoLog);
        std::cout << "Vertex shader info log says: " << infoLog << std::endl;

        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderInfoLog(fragmentShader, 256, NULL, infoLog);
        std::cout << "Fragment shader info log says: " << infoLog << std::endl;

        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        glGetProgramInfoLog(program, 256, NULL, infoLog);
        std::cout << "Progam info log says: " << infoLog << std::endl;

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        float vertices[] = {
            -1.0f, -1.0f, 0.0f, // bottom left
            -1.0f, 1.0f,  0.0f, // top left
            1.0f,  -1.0f, 0.0f, // bottom right
            -1.0f, 1.0f,  0.0f, // top left
            1.0f,  -1.0f, 0.0f, // bottom right
            1.0f,  1.0f,  0.0f, // top right
        };

        GLuint VAO;
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        glEnableVertexAttribArray(0);

        GLuint VBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), 0);

        glUseProgram(program);

        // maxitersLocation = glGetUniformLocation(program, "maxiters");
        // GLuint xsizeLocation = glGetUniformLocation(program, "xsize");
        // GLuint ysizeLocation = glGetUniformLocation(program, "ysize");
        // std::cout << "Maxiters location is " << maxitersLocation << std::endl;

        // int xsize;
        // int ysize;
        // glfwGetWindowSize(window, &xsize, &ysize);
        // std::cout << "Window size is " << xsize << " x " << ysize << std::endl;

        // glUniform1f(maxitersLocation, 10);
    }
    void Test2::Render() {
        if (!m_active) {
            return;
        }
        static float iters = 0.0f;

        glUniform1f(maxitersLocation, iters);
        glClearColor(1, 0.5, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        auto imageID = _<ImageBank>().GetImage("DefaultSceneBackground");

        glBindTexture(GL_TEXTURE_2D, imageID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
        glFinish();

        iters = iters + 0.1;
    }
    void Test2::Stop() {
        m_active = false;
        glfwDestroyWindow(window);
        glDeleteBuffers(1, &m_vbo);
        glDeleteVertexArraysOES(1, &m_vao);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
    }
}