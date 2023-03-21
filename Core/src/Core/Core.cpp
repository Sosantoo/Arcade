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

void Core::Core::test() {
    auto &gameInterface = _game.getInterface();
    auto &graphicalInterface = _graphical.getInterface();

    IEvent::EventHandler event = {};
    gameInterface.start(graphicalInterface, event);
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
    core.start(baseGraphicalsLibsName, "./lib/testGame.so");
    return 0;
}
