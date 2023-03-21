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
    std::cout << "[GAME test] Loading" << '\n';
}

void calledLast() {
    std::cout << "[GAME test] UnLoading" << '\n';
}

// extern "C" {
//     IGame *create() {
//         return new AGame;
//     }
// }
