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
