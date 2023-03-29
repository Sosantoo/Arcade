/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalNcurses
*/

#include "AGraphicalNcurses.hpp"
#include <iostream>
#include <ncurses.h>

AGraphicalNcurses::AGraphicalNcurses()
{
    setlocale(LC_ALL, "");
    if (!initscr())
        throw std::runtime_error("Error: initscr() failed");
    cbreak();
    noecho();
    curs_set(0);
    nonl();
    keypad(stdscr, TRUE);
    wtimeout(stdscr, 100);
    nodelay(stdscr, true);
    intrflush(stdscr, true);
}

AGraphicalNcurses::~AGraphicalNcurses()
{
    endwin();
}

void AGraphicalNcurses::loadResource()
{
    std::cout << "[nCurses loadResource] loadResource" << std::endl;
}

void AGraphicalNcurses::destroyRessource()
{
    std::cout << "[nCurses loadRessousreces] destroyRessource" << std::endl;
}

void AGraphicalNcurses::openWindow()
{
    std::cout << "[nCurses] openWindow" << std::endl;
};

void AGraphicalNcurses::closeWindow()
{
    std::cout << "[nCurses] closeWindow" << std::endl;
    // graphicalInfo.isOpen = false;
    // endwin();
};

void AGraphicalNcurses::initWindow(std::string name, std::pair<size_t, size_t> size){
    WINDOW *window = newwin(size.first, size.second, graphicalInfo.y, graphicalInfo.x);
    box(window, 0, 0);
    refresh();
    wrefresh(window);
};

bool AGraphicalNcurses::windowIsOpen()
{
    return (graphicalInfo.isOpen);
};

void AGraphicalNcurses::clear()
{
    erase();
};

void AGraphicalNcurses::display()
{
    refresh();
};

void AGraphicalNcurses::eventPollEvent(){
    while (graphicalInfo.window != nullptr) {
        int key = wgetch(graphicalInfo.window);
        switch (key) {
            case KEY_UP:
            case 'z': return callEvent(IEvent::EventType::UP_pressed);

            case KEY_DOWN:
            case 's': return callEvent(IEvent::EventType::DOWN_pressed);

            case KEY_LEFT:
            case 'q': return callEvent(IEvent::EventType::LEFT_pressed);

            case KEY_RIGHT:
            case 'd': return callEvent(IEvent::EventType::RIGHT_pressed);

            case 'n': return callEvent(IEvent::EventType::NEXT_LIB);

            case 27: return callEvent(IEvent::EventType::QUIT);

            default: std::cerr << "--! Event Handler Unknown key: " << key << std::endl; break;
        }
    }

};

IClock &AGraphicalNcurses::getClock(){
    return _clock;
};
