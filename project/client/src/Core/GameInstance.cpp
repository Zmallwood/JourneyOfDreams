#include "GameInstance.h"
#include "Graphics/Graphics.h"
#include "Rendering/Shaders/DefaultShaderFragment.h"
#include "Rendering/Shaders/DefaultShaderVertex.h"

namespace zw
{
    struct context
    {
        int x;
    };

    void loop_fn(void *arg)
    {
        glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a triangle from the 3 vertices
        glDrawArrays(GL_TRIANGLES, 0, 3);

        SDL_GL_SwapWindow(_<Graphics>().Window().get());
    }

    EM_BOOL onopen(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData)
    {
        puts("onopen");
        std::cout << "connected\n";
        EMSCRIPTEN_RESULT result;
        result = emscripten_websocket_send_utf8_text(websocketEvent->socket, "hoge");
        if (result)
        {
            printf("Failed to emscripten_websocket_send_utf8_text(): %d\n", result);
        }
        std::cout << "sent message\n";
        return EM_TRUE;
    }
    EM_BOOL onerror(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData)
    {
        puts("onerror");

        return EM_TRUE;
    }
    EM_BOOL onclose(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData)
    {
        puts("onclose");

        return EM_TRUE;
    }
    EM_BOOL onmessage(int eventType, const EmscriptenWebSocketMessageEvent *websocketEvent, void *userData)
    {
        puts("onmessage");
        if (websocketEvent->isText)
        {
            // For only ascii chars.
            printf("message: %s\n", websocketEvent->data);
        }

        EMSCRIPTEN_RESULT result;
        result = emscripten_websocket_close(websocketEvent->socket, 1000, "no reason");
        if (result)
        {
            printf("Failed to emscripten_websocket_close(): %d\n", result);
        }
        return EM_TRUE;
    }

    void GameInstance::Run()
    {
        if (!emscripten_websocket_is_supported())
        {
            return;
        }
        EmscriptenWebSocketCreateAttributes ws_attrs = { "ws://localhost:1238", NULL, EM_TRUE };

        EMSCRIPTEN_WEBSOCKET_T ws = emscripten_websocket_new(&ws_attrs);
        emscripten_websocket_set_onopen_callback(ws, NULL, onopen);
        emscripten_websocket_set_onerror_callback(ws, NULL, onerror);
        emscripten_websocket_set_onclose_callback(ws, NULL, onclose);
        emscripten_websocket_set_onmessage_callback(ws, NULL, onmessage);

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