/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "opengl.hpp"

std::unordered_map<int, bool> keyState;

void keyPressed(unsigned char key, int x, int y) {
    keyState[key] = true;
}

void keyReleased(unsigned char key, int x, int y) {
    keyState[key] = false;
}

void idleFunc() {
    glutPostRedisplay();
}

void AGraphical::initWindow(std::string WindowName, std::pair<size_t, size_t> size) const {
    std::cout << "initWindow" << std::endl;

    int ac = 1;
    char *av[3] = {"program name", "ee", NULL};
    glutInit(&ac, av);
    glutInitWindowSize(size.first, size.second);
    glutCreateWindow(WindowName.c_str());
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutKeyboardUpFunc(keyReleased);
}

void AGraphical::openWindow() const {
    std::cout << "openWindow" << std::endl;

    if (_eventBinding == nullptr) {
        std::cout << "no event binded" << std::endl;
        return;
    }


    (*_eventBinding)[IEvent::EventType::UP_pressed]();
    (*_eventBinding)[IEvent::EventType::LEFT_pressed]();
    (*_eventBinding)[IEvent::EventType::DOWN_pressed]();
    (*_eventBinding)[IEvent::EventType::RIGHT_pressed]();

    // glutMainLoop();
    // launchSnakeTest(1, NULL);
}

void AGraphical::closeWindow() const {
    std::cout << "closeWindow" << std::endl;
}

void AGraphical::loadEventBindings(IEvent::EventHandler &eventBinding) {
    std::cout << "event binded" << std::endl;
    _eventBinding = &eventBinding;
}
