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
    std::cout << "[GAME] Loading" << '\n';
}

void calledLast() {
    std::cout << "[GAME] UnLoading" << '\n';
}

extern "C" {
    IGame *create() {
        return new AGame;
    }
}
