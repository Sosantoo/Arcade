/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "snake.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[GAME snake] Loading" << '\n';
}

void calledLast() {
    std::cout << "[GAME snake] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IGame> create() {
        return std::make_unique<AGameSnake>();
    }
}
