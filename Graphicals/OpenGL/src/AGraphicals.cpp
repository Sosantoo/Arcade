/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "opengl.hpp"

std::unordered_map<int, bool> keyState;

static void error_callback(int error, const char *description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

void AGraphical::openWindow()
{
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    if (!window)
        throw std::runtime_error("Failed to create window");
    glfwMakeContextCurrent(window);
}

void AGraphical::initWindow(std::string name, std::pair<size_t, size_t> size)
{
    glfwSetErrorCallback(error_callback);
    glewExperimental = GL_TRUE;
    if (!glfwInit()) {
        throw std::runtime_error("GLFW initialization failed");
    }
    if (!glewInit()) {
        throw std::runtime_error("GLEW initialization failed");
    }
};

void AGraphical::closeWindow()
{
    glfwTerminate();
    glfwDestroyWindow(window);
};

bool AGraphical::windowIsOpen()
{
    return (!glfwWindowShouldClose(window));
};

void AGraphical::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
};

void AGraphical::callEvent(const IEvent::EventType eventType)
{
    if (_eventBinding == nullptr) {
        std::cout << "no event binded" << std::endl;
        return;
    }
    (*_eventBinding)[eventType]();
    /* Poll for and process events */
    // glfwPollEvents();
}

void AGraphical::display()
{
    glfwSwapBuffers(window);
    /* Poll for and process events */
    glColor3f( 1.0, 1.0, 1.0 );
    //glColor3f( 1.0, 0.0, 0.0 );
};
