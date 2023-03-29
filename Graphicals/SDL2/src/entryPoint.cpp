/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGraphicalSDL2.hpp"
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[sdl2] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[sdl2] UnLoading" << '\n';
}

extern "C" {
IGraphical *create()
{
    return new AGraphicalSDL2;
}
}
