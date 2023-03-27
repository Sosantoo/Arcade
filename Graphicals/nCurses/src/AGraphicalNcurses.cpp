/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalNcurses
*/

#include "ncurses.hpp"

void AGraphicalNcurses::loadResource()
{
    std::cout << "[nCurses loadResource] destroyRessource" << std::endl;
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
    graphicalInfo.isOpen = false;
    endwin();
};

void AGraphicalNcurses::initWindow(std::string, std::pair<size_t, size_t>)
{
    std::cout << "[nCurses] initWindow" << std::endl;
    initscr();
    cbreak();
    noecho();

    getmaxyx(stdscr, graphicalInfo.yMax, graphicalInfo.xMax);
    graphicalInfo.win = newwin(15, graphicalInfo.xMax -100, graphicalInfo.yMax /2, 30);
    box(graphicalInfo.win, 0, 0);
    refresh();
    wrefresh(graphicalInfo.win);
    keypad(graphicalInfo.win, TRUE);
    graphicalInfo.isOpen = true;
};

bool AGraphicalNcurses::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphicalNcurses::clear()
{
    std::cout << "[nCurses] clear" << std::endl;
};


void AGraphicalNcurses::display()
{
    mvwprintw(graphicalInfo.win, 1, graphicalInfo.xMax / 3 - 15, "Arcade");
};

void AGraphicalNcurses::eventPollEvent()
{
    int key = wgetch(graphicalInfo.win);

    switch (key) {
    case KEY_UP:
    case 'z':
        callEvent(IEvent::EventType::UP_pressed);
        break;
    case KEY_DOWN:
    case 's':
        callEvent(IEvent::EventType::DOWN_pressed);
        break;
    case KEY_LEFT:
    case 'q':
        callEvent(IEvent::EventType::LEFT_pressed);
        break;
    case KEY_RIGHT:
    case 'd':
        callEvent(IEvent::EventType::RIGHT_pressed);
        break;
    case 27:
        callEvent(IEvent::EventType::QUIT);
        break;
    default:
        std::cerr << "--! Event Handler Unknown key: " << key << std::endl;
        break;
    }
};

IClock &AGraphicalNcurses::getClock() {
    return _clock;
};
