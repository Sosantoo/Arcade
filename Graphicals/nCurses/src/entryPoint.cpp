/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGraphicalNcurses.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[Ncurses] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[Ncurses] UnLoading" << '\n';
}

extern "C" {
IGraphical *create()
{
    return new AGraphicalNcurses;
}
}
