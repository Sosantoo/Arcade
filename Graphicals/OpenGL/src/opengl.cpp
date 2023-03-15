/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** opengl
*/

#include "opengl.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[sopengl] Loading" << '\n';
}

void calledLast() {
    std::cout << "[sopengl] UnLoading" << '\n';
}
