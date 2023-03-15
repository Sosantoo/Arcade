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

void Core::Core::testGraphicals() {
    IGraphical *interface = _graphical.getInterface();
    interface->display();
    interface->openWindow();
    interface->closeWindow();
    interface->createGrid();
    interface->updateCell();
    interface->setName();
    interface->setSize();
}

void Core::Core::testGame() {
    IGame *interface = _game.getInterface();
    interface->start();
    interface->stop();
    interface->reset();
    interface->getLife();
    interface->getScore();
    interface->handleEvent();
    interface->checkAroundCells();
    interface->move(1, 1);
}

void Core::Core::start(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    std::cout << "start" << std::endl;
    _graphical.load(GraphicalsLibPath);
    _game.load(GameLibPath);

    testGraphicals();
    testGame();
}

int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    Core::Core core;
    Core::libWrapper libs("./lib");

    libs.displayavailableLib();
    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw CoreExceptions::LibUnknowExceptions(baseGraphicalsLibsName);
    core.start(baseGraphicalsLibsName, "./lib/arcade_menu.so");
    return 0;
}
