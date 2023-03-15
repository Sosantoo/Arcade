/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "sdl2.hpp"

AGraphicals::AGraphicals()
{
}

AGraphicals::~AGraphicals()
{
}

void AGraphicals::display() {
    std::cout << "[ssdl2] display" << std::endl;
};

void AGraphicals::openWindow() {
    std::cout << "[ssdl2] openWindow" << std::endl;
};

void AGraphicals::closeWindow() {
    std::cout << "[ssdl2] closeWindow" << std::endl;
};

void AGraphicals::createGrid() {
    std::cout << "[ssdl2] createGrid" << std::endl;
};

void AGraphicals::updateCell() {
    std::cout << "[ssdl2] updateCell" << std::endl;
};

void AGraphicals::setName() {
    std::cout << "[ssdl2] setName" << std::endl;
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
