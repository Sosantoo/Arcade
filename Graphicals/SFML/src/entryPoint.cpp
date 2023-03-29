/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "../include/AGraphicalSFML.hpp"
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[sfml] Loading" << '\n';
}

void calledLast() {
    std::cout << "[sfml] UnLoading" << '\n';
}

extern "C" {
    IGraphical *create() {
        return new AGraphicalSFML;
    }
}