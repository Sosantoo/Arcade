/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory
*/

#include "GraphicalFactorySFML.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void GraphicalFactorySFML::loadResource()
{
    std::cout << "[SFML] loadResource" << std::endl;
}

void GraphicalFactorySFML::destroyRessource()
{
    std::cout << "[SFML] destroyRessource" << std::endl;
}

std::unique_ptr<IClock> GraphicalFactorySFML::createIClock() {
    return std::make_unique<ClockSFML>();
}

std::unique_ptr<IWindow> GraphicalFactorySFML::createWindow(std::string name, size_t width, size_t height) {
    auto window = std::make_unique<WindowSFML>();
    window->initWindow(name, width, height);
    return window;
}
