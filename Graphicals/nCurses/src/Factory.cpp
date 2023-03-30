/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory
*/

#include "GraphicalFactoryNcurses.hpp"

void GraphicalFactoryNcurses::loadResource() {
    std::cout << "[NCURSES] loadResource" << std::endl;
};

void GraphicalFactoryNcurses::destroyRessource() {
    std::cout << "[NCURSES] destroyRessource" << std::endl;
};

std::unique_ptr<IClock> GraphicalFactoryNcurses::createIClock() {
    return std::make_unique<ClockNcurses>();
}

std::unique_ptr<IWindow> GraphicalFactoryNcurses::createWindow(std::string name, size_t width, size_t height) {
    auto window = std::make_unique<WindowNcurses>();
    window->initWindow(name, width, height);
    return std::move(window);
}
