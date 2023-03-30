/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** entryPoint
*/

#include "AGameTest.hpp"
#include <memory>
#include <iostream>

void __attribute__((constructor)) calledFirst();
void __attribute__((destructor)) calledLast();

void calledFirst()
{
    std::cout << "[GAME test] Loading" << '\n';
}

void calledLast()
{
    std::cout << "[GAME test] UnLoading" << '\n';
}

extern "C" {
    std::unique_ptr<IGame> create() {
        return std::make_unique<AGameTest>();
    }
}
