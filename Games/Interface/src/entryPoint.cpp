/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGame.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[GAME lib] Loading" << '\n';
}

void calledLast() {
    std::cout << "[GAME lib] UnLoading" << '\n';
}

extern "C" {
    IGame *create() {
        return new AGame;
    }
}
