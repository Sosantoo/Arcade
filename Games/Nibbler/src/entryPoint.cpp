/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGameNibbler.hpp"
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[GAME nibbler] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[GAME nibbler] UnLoading" << '\n';
}

extern "C" {
IGame *create()
{
    return new AGameNibller;
}
}
