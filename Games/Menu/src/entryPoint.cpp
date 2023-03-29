/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGameMenu.hpp"
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[GAME menu] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[GAME menu] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IGame> create() {
        return std::make_unique<AGameMenu>();
    }
}
