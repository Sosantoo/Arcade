/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "GraphicalFactoryNcurses.hpp"

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst() {
    std::cout << "[Ncurses] Loading" << '\n';
}

void calledLast() {
    std::cout << "[Ncurses] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IGraphicalFactory> create() {
        return std::make_unique<GraphicalFactoryNcurses>();
    }
}
