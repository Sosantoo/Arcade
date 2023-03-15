/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#include "arcade.hpp"

Core::Core::Core(libWrapper &libs)
    : _libs{libs}
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

void Core::Core::test() {
    testGraphicals();
    nextGraphicsLibrary();
    nextGraphicsLibrary();
    nextGraphicsLibrary();
    testGraphicals();
    testGame();
}

void Core::Core::start(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    _graphical_details = _libs.getLibBypath(GraphicalsLibPath);
    _game_details = _libs.getLibBypath(GameLibPath);
    _graphical.load(_graphical_details);
    _game.load(_game_details);
    test();
}

int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    libWrapper libs("./lib");

    libs.displayavailableLib();
    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw CoreExceptions::LibUnknowExceptions(baseGraphicalsLibsName);

    Core::Core core(libs);
    core.start(baseGraphicalsLibsName, "./lib/arcade_menu.so");
    return 0;
}
