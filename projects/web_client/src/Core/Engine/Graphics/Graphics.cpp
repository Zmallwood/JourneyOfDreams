/* Copyright (c) 2024 Andreas Åkerberg. */

#include "Graphics.h"
#include "Core/Configuration/ClientProperties.h"

/* Graphics class implementation. */

EM_JS(int, canvas_get_width, (), { return window.innerWidth; });
EM_JS(int, canvas_get_height, (), { return window.innerHeight; });

namespace JourneyOfDreams
{
  Graphics::Graphics() {
    SDL_Init(SDL_INIT_EVERYTHING);
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    m_window = glfwCreateWindow(canvas_get_width(), canvas_get_height(),
                                "The Window Title", NULL, NULL);
    glfwMakeContextCurrent(m_window);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }

  void Graphics::ClearCanvas() {
    /* Clear canvas at the beginning of each frame. */
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Graphics::PresentCanvas() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
    glFinish();
  }

  GLFWwindow *Graphics::Window() {
    return m_window;
  }
}