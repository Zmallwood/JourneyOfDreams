//  Copyright (C) 2024 Andreas Åkerberg

#include "InputManager.h"
#include "Core/Engine/Graphics/Graphics.h"
#include "KeyboardInput.h"
#include "MouseInput.h"

namespace JourneyOfDreams
{
    static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        if (action == GLFW_PRESS)
        {
            _<KeyboardInput>().OnKeyPress(key);
        }
        else if (action == GLFW_RELEASE)
        {
            _<KeyboardInput>().OnKeyRelease(key);
        }
    }

    static void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
    {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            _<MouseInput>().LeftButton().OnPress();
        }
        else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        {
            _<MouseInput>().LeftButton().OnRelease();
        }
        else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        {
            _<MouseInput>().RightButton().OnPress();
        }
        else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        {
            _<MouseInput>().RightButton().OnRelease();
        }
    }

    static void CharacterCallback(GLFWwindow *window, unsigned int codepoint)
    {
        _<KeyboardInput>().AppendTextInput(std::string(1, (char)codepoint));
    }

    InputManager::InputManager()
    {
        glfwSetKeyCallback(_<Graphics>().Window(), KeyCallback);
        glfwSetMouseButtonCallback(_<Graphics>().Window(), MouseButtonCallback);
        glfwSetCharCallback(_<Graphics>().Window(), CharacterCallback);
    }
}