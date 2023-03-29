/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Window
*/

#include "GraphicalFactoryNcurses.hpp"
#include <ncurses.h>

void WindowNcurses::initWindow(std::string name, size_t width, size_t height)
{
    std::cout << "[nCurses] initWindow" << std::endl;
    initscr();
    cbreak();
    noecho();

    getmaxyx(stdscr, yMax, xMax);
    window = newwin(15, xMax -100, yMax /2, 30);
    box(window, 0, 0);
    refresh();
    wrefresh(window);
    keypad(window, TRUE);
    isOpen = true;
};

void WindowNcurses::closeWindow()
{
    std::cout << "[nCurses] closeWindow" << std::endl;
    isOpen = false;
    endwin();
};

bool WindowNcurses::windowIsOpen()
{
    return isOpen;
};

void WindowNcurses::clear()
{
};


void WindowNcurses::display()
{
    mvwprintw(window, 1, xMax / 3 - 15, "Arcade");
};

void WindowNcurses::eventPollEvent()
{
    int key = wgetch(window);

    switch (key) {
    case -1:
        return;
    case KEY_UP:
    case 'z':
        return callEvent(IWindow::EventType::UP_pressed);

    case KEY_DOWN:
    case 's':
        return callEvent(IWindow::EventType::DOWN_pressed);

    case KEY_LEFT:
    case 'q':
        return callEvent(IWindow::EventType::LEFT_pressed);

    case KEY_RIGHT:
    case 'd':
        return callEvent(IWindow::EventType::RIGHT_pressed);

    case 'n':
    return callEvent(IWindow::EventType::NEXT_LIB);

    case 27:
        return callEvent(IWindow::IWindow::EventType::QUIT);

    default:
        std::cerr << "--! Event Handler Unknown key: " << key << std::endl;
        break;
    }
};

void WindowNcurses::callEvent(const IWindow::EventType eventType) {
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void WindowNcurses::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding.insert(eventBinding.begin(), eventBinding.end());
};
