/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "menu.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[Menu] Loading" << '\n';
}

void calledLast() {
    std::cout << "[Menu] UnLoading" << '\n';
}

// extern "C" {
//     IGame *create() {
//         return new AGame;
//     }
// }
