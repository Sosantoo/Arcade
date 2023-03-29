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

void Core::Core::init(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    _graphical_details = _libs.getLibBypath(GraphicalsLibPath);
    _game_details = _libs.getLibBypath(GameLibPath);

    loadStack();
}

void Core::Core::launchGame() {
    auto gameInterface = _game.getInterface();
    auto graphicalInterface = _graphical.getInterface();

    while(graphicalInterface->windowIsOpen()) {
        graphicalInterface->eventPollEvent();
        graphicalInterface = _graphical.getInterface();
        gameInterface = _game.getInterface();

        graphicalInterface->clear();
        gameInterface->processGameTick(graphicalInterface->getClock());
        graphicalInterface->displayEntity(gameInterface->getEntity());
        graphicalInterface->display();
    }
}

void Core::Core::loadStack() {
    loadGame();
    loadGraphical();
}

void Core::Core::loadGraphical() {
    _graphical.load(_graphical_details, Lib::_GRAPHICALS_);
    auto &graphicalInterface = _graphical.getInterface();

    graphicalInterface->loadEventBindings(getCoreEventBind());
    graphicalInterface->loadResource();
    graphicalInterface->initWindow(
        _game_details.name + " " + _graphical_details.name,
        {800, 800}
    );

    graphicalInterface->loadEventBindings(_game.getInterface()->getEventBinding());
}

void Core::Core::loadGame() {
    _game.load(_game_details, Lib::_GAMES_);
}


int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    libWrapper libs("./lib");

    // libs.displayavailableLib();
    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw CoreExceptions::LibUnknowExceptions(baseGraphicalsLibsName);

    Core::Core core(libs);
    core.init(baseGraphicalsLibsName, "./lib/testGame.so");
    core.launchGame();
    return 0;
}
