/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalEvent
*/

#include "sdl2.hpp"

void AGraphical::loadEventBindings(EventHandler &eventBinding) {
    _eventBinding = &eventBinding;
}

void AGraphical::callEvent(const IEvent::EventType eventType)
{
    if (!_eventBinding)
        throw std::runtime_error("--! [GAME Logic] no event binded");
    (*_eventBinding)[eventType]();
}
