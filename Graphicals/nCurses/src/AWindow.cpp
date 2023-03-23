/*
** EPITECH PROJECT, 2023
** tmp
** File description:
** AWindow
*/

#include "ncurses.hpp"

void AGraphical::openWindow()
{
    std::cout << "[nCurses] openWindow" << std::endl;
};

void AGraphical::closeWindow()
{
    std::cout << "[nCurses] closeWindow" << std::endl;
    graphicalInfo.isOpen = false;
    endwin();
};

void AGraphical::initWindow(std::string, std::pair<size_t, size_t>)
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

bool AGraphical::windowIsOpen()
{
    return graphicalInfo.isOpen;
};

void AGraphical::clear()
{
    std::cout << "[nCurses] clear" << std::endl;
};


void AGraphical::display()
{
    mvwprintw(graphicalInfo.win, 1, graphicalInfo.xMax / 3 - 15, "Arcade");
    EventPool(getch());
};
