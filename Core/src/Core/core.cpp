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

static int test(IGraphical *interface) {
    interface->display();
    interface->openWindow();
    interface->closeWindow();
    interface->createGrid();
    interface->updateCell();
    interface->setName();
    interface->setSize();
    return 1;
}

int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    std::cout << baseGraphicalsLibsName << std::endl;
    Core::libWrapper libs("./lib");

    InterfaceWrapper<IGraphical> graphics;
    InterfaceWrapper<IGame> game;

    for (const auto &lib : libs.availableLib())
        std::cout << lib.first << ": " << lib.second << std::endl;
    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw CoreExceptions::LibUnknowExceptions(baseGraphicalsLibsName);

    graphics.load(libs.availableLib()[baseGraphicalsLibsName]);
    test(graphics.getInterface());
    return 0;
}
