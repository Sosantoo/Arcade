/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory
*/

#include "GraphicalFactorySDL2.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void GraphicalFactorySDL2::loadResource()
{
    std::cout << "[SDL2] loadResource" << std::endl;
}

void GraphicalFactorySDL2::destroyRessource()
{
    std::cout << "[SDL2] destroyRessource" << std::endl;
    SDL_Quit();
}

std::unique_ptr<IClock> GraphicalFactorySDL2::createIClock() {
    return std::make_unique<ClockSDL2>();
}

std::unique_ptr<IWindow> GraphicalFactorySDL2::createWindow(std::string name, size_t width, size_t height) {
    auto window = std::make_unique<WindowSDL2>();
    window->initWindow(name, width, height);
    return std::move(window);
}
