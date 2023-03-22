/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicals
*/

#include "opengl.hpp"

std::unordered_map<int, bool> keyState;

void AGraphical::openWindow()
{
    return;
}

void AGraphical::initWindow(std::string name, std::pair<size_t, size_t> size)
{

};

void AGraphical::closeWindow()
{
};

bool AGraphical::windowIsOpen()
{
    return 1;
};

void AGraphical::clear()
{

};

void AGraphical::callEvent(const IEvent::EventType eventType)
{
    if (_eventBinding == nullptr) {
        std::cout << "no event binded" << std::endl;
        return;
    }
    (*_eventBinding)[eventType]();
}

void AGraphical::display()
{
};
