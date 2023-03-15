/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** main
*/

#include "arcade.hpp"

int main(const int ac, const char **av)
{
    try {
        if (ac != 2) throw std::runtime_error("invalid arguments");
        coreEntryPoint(av[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}
