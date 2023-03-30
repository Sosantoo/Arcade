/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include <memory>
#include "GraphicalFactorySDL2.hpp"
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[sdl2] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[sdl2] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IGraphicalFactory> create() {
        return std::make_unique<GraphicalFactorySDL2>();
    }
}
