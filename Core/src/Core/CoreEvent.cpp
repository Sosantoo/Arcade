/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreEvent
*/

#include "Core/Core.hpp"
#include "Exceptions/Exceptions.hpp"

void Core::Core::nextGraphicsLibrary() {
    _graphical.getWindowInterface().closeWindow();
    _graphical.getInterface().destroyRessource();
    _graphical.load(_LibFileManager.getNextGraphicalsLib(_graphical._libDetails));
    bindEvents();
}

void Core::Core::nextGameLibrary() {
    _game.load(_LibFileManager.getNextGraphicalsLib(_game._libDetails));
    bindEvents();
}

void Core::Core::restartGame() {
    _game.load(_game._libDetails);
    bindEvents();
}

void Core::Core::goToMenu() {
    _game.load({
        .name = "arcade_menu.so",
        .path = "./lib/arcade_menu.so",
        .type = Lib::_GAMES_,
    });

    bindEvents();
}

void Core::Core::closeGraphical() {
}
