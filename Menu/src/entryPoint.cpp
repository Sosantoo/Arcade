/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "Menu.hpp"
#include <memory>
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[Menu] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[Menu] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IMenu> create() {
        return std::make_unique<Menu>();
    }
}
