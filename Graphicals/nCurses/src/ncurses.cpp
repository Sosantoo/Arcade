/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** ncurses
*/

#include "ncurses.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[ncurses] Loading" << '\n';
}

void calledLast() {
    std::cout << "[ncurses] UnLoading" << '\n';
}
