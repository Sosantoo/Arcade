/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** sdl2
*/

#include "sdl2.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[ssdl2] Loading" << '\n';
}

void calledLast() {
    std::cout << "[ssdl2] UnLoading" << '\n';
}
