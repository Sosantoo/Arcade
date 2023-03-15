/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** actionsHandler
*/

#include "arcade.hpp"

void Core::Core::nextGraphicsLibrary() {
    Lib::lib_t nextLib = _libs.getNextGraphicalsLib(_graphical_details);
    _graphical_details = nextLib;
    _graphical.load(nextLib);
}

void Core::Core::nextGame() {
    Lib::lib_t nextLib = _libs.getNextGraphicalsLib(_game_details);
    _game_details = nextLib;
    _game.load(nextLib);
}

void Core::Core::restartGame() {
   _game.load(_game_details);
}

void Core::Core::goToMenu() {
    _game.load({
        .name = "arcade_menu.so",
        .path = "./lib/arcade_menu.so",
        .type = Lib::_GAMES_,
    });
}

void Core::Core::exit() {
    std::exit(0);
}
