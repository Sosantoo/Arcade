/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "opengl.hpp"

AGraphicals::AGraphicals()
{
}

AGraphicals::~AGraphicals()
{
}

void AGraphicals::display() {
    std::cout << "[opengl] display" << std::endl;
};

void AGraphicals::openWindow() {
    std::cout << "[opengl] openWindow" << std::endl;
};

void AGraphicals::closeWindow() {
    std::cout << "[opengl] closeWindow" << std::endl;
};

void AGraphicals::createGrid() {
    std::cout << "[opengl] createGrid" << std::endl;
};

void AGraphicals::updateCell() {
    std::cout << "[opengl] updateCell" << std::endl;
};

void AGraphicals::setName() {
    std::cout << "[opengl] setName" << std::endl;
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
