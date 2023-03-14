/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#include "arcade.hpp"

Core::Core::Core()
{

}

Core::Core::~Core()
{

}

int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    Core::libWrapper libs("./lib");

    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw std::runtime_error("Libs not available");

    for (const auto &lib : libs.availableLib())
        std::cout << lib.first << ": " << lib.second << std::endl;

    return 0;
}
