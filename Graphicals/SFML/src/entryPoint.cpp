/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "GraphicalFactorySFML.hpp"
#include <memory>
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
    std::unique_ptr<IGraphicalFactory> create() {
        return std::make_unique<GraphicalFactorySFML>();
    }
}
