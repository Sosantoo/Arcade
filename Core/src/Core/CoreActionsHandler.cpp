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

    _graphical.load(nextLib, Lib::_GRAPHICALS_);
}

void Core::Core::nextGameLibrary() {
    Lib::lib_t nextLib = _libs.getNextGraphicalsLib(_game_details);
    _game_details = nextLib;

    _game.load(nextLib, Lib::_GAMES_);
}

void Core::Core::restartGame() {
   _game.load(_game_details, Lib::_GAMES_);
}

void Core::Core::goToMenu() {
    _game.load({
        .name = "arcade_menu.so",
        .path = "./lib/arcade_menu.so",
        .type = Lib::_GAMES_,
    }, Lib::_GAMES_);
}

void Core::Core::exit() {
    std::exit(0);
}

IEvent::EventHandler &Core::Core::getCoreEventBind() {
    return (event = {
        {IEvent::EventType::NEXT_LIB, [this](){ this->nextGraphicsLibrary(); }},
        {IEvent::EventType::NEXT_GAME, [this](){ this->nextGameLibrary(); }},
        {IEvent::EventType::RESTART, [this](){ this->restartGame(); }},
        {IEvent::EventType::GO_TO_MENU, [this](){ this->goToMenu(); }},
    });
}
