/*
** EPITECH PROJECT, 2023
** arcadeMirror
** File description:
** actionsHandler
*/

#include "arcade.hpp"

void Core::Core::nextGraphicsLibrary() {
    closeGraphical();
    _graphical_details = _libs.getNextGraphicalsLib(_graphical_details);;
    loadGraphical();
}

void Core::Core::nextGameLibrary() {
    _game_details = _libs.getNextGraphicalsLib(_game_details);;
    loadStack();
}

void Core::Core::restartGame() {
    closeGraphical();
    _game.load(_game_details, Lib::_GAMES_);
    loadStack();
}

void Core::Core::goToMenu() {
    _game.load({
        .name = "arcade_menu.so",
        .path = "./lib/arcade_menu.so",
        .type = Lib::_GAMES_,
    }, Lib::_GAMES_);

    loadStack();
    launchGame();
}

void Core::Core::closeGraphical() {
    _graphical.getInterface()->closeWindow();
    _graphical.getInterface()->destroyRessource();
}

IEvent::EventHandler &Core::Core::getCoreEventBind() {
    return (event = {
        {IEvent::EventType::NEXT_LIB, [this](){ this->nextGraphicsLibrary(); }},
        {IEvent::EventType::NEXT_GAME, [this](){ this->nextGameLibrary(); }},
        {IEvent::EventType::RESTART, [this](){ this->restartGame(); }},
        {IEvent::EventType::GO_TO_MENU, [this](){ this->goToMenu(); }},
        {IEvent::EventType::QUIT, [this](){ this->closeGraphical(); }},
    });
}
