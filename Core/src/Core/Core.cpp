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

void Core::Core::launch() {
    auto &gameInterface = _game.getInterface();
    auto &graphicalInterface = _graphical.getInterface();

    gameInterface.start(
        graphicalInterface,
        getCoreEventBind()
    );
}

void Core::Core::start(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    _graphical_details = _libs.getLibBypath(GraphicalsLibPath);
    _game_details = _libs.getLibBypath(GameLibPath);

    _graphical.load(_graphical_details, Lib::_GRAPHICALS_);
    _game.load(_game_details, Lib::_GAMES_);

    launch();
}

int coreEntryPoint(const std::string &baseGraphicalsLibsName)
{
    libWrapper libs("./lib");

    // libs.displayavailableLib();
    if (!libs.isAvailable(baseGraphicalsLibsName))
        throw CoreExceptions::LibUnknowExceptions(baseGraphicalsLibsName);

    Core::Core core(libs);
    core.start(baseGraphicalsLibsName, "./lib/testGame.so");
    return 0;
}
