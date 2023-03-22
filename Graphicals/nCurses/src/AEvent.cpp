/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AEvent
*/

#include "ncurses.hpp"

void AGraphical::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding.insert(eventBinding.begin(), eventBinding.end());
}

void AGraphical::callEvent(const IEvent::EventType eventType)
{
    if (_eventBinding.count(eventType) <= 0)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    _eventBinding[eventType]();
}

void AGraphical::EventPool(int key)
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
