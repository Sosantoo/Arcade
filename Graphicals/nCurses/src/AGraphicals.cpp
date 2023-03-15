/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** AGraphicals
*/

#include "ncurses.hpp"

AGraphicals::AGraphicals()
{
}

AGraphicals::~AGraphicals()
{
}

void AGraphicals::display() {
    std::cout << "[ncurses] display" << std::endl;
};

void AGraphicals::openWindow() {
    std::cout << "[ncurses] openWindow" << std::endl;
};

void AGraphicals::closeWindow() {
    std::cout << "[ncurses] closeWindow" << std::endl;
};

void AGraphicals::createGrid() {
    std::cout << "[ncurses] createGrid" << std::endl;
};

void AGraphicals::updateCell() {
    std::cout << "[ncurses] updateCell" << std::endl;
};

void AGraphicals::setName() {
    std::cout << "[ncurses] setName" << std::endl;
};

int AGraphicals::setSize() {
    return 0;
};

int AGraphicals::getState() {
    return 0;
};

int AGraphicals::getKey() {
    return 0;
};

extern "C" IGraphical* create() {
    return new AGraphicals;
}

extern "C" void destroy(AGraphicals* p) {
    (void) p;
    // delete p;
}
