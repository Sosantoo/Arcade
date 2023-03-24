/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AEvent
*/

#include "ncurses.hpp"

void AGraphicalNcurses::EventPool(int key)
{
    // std::cout << "[nCurses] call EventPool " << key << std::endl;
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
        std::cerr << "Unknown key: " << key << std::endl;
        break;
    }
};
