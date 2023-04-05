/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Factory
*/

#include "GraphicalFactoryNcurses.hpp"

void GraphicalFactoryNcurses::loadResource() {
    std::cout << "[NCURSES] loadResource" << std::endl;
    //init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    wtimeout(stdscr, 100);
    nodelay(stdscr, true);
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
    return window;
}
