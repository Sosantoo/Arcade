/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "opengl.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[openGL] Loading" << '\n';
}

void calledLast() {
    std::cout << "[openGL] UnLoading" << '\n';
}

extern "C" {
    IGraphical *create() {
        return new AGraphical;
    }
}