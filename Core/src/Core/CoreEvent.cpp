/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreEvent
*/

#include "Core/Core.hpp"
#include "Exceptions/Exceptions.hpp"
#include <iostream>

void Core::Core::nextGraphicsLibrary() {
    _graphical.getWindowInterface().closeWindow();
    _graphical.getInterface().destroyRessource();

    _graphical._libDetails = _LibFileManager.getNextGraphicalsLib(_graphical._libDetails);
    _graphical.load(_graphical._libDetails);
    bindEvents();
    std::cout << "[CORE] " << _graphical._libDetails.name << " lib loaded" << std::endl;
}

void Core::Core::nextGameLibrary() {
    _game._libDetails = _LibFileManager.getNextGameLib(_game._libDetails);
    _game.load(_game._libDetails);
    gameState = Core::GameState::GAME_LOOP;
    bindEvents();
    std::cout << "[CORE] " << _graphical._libDetails.name << " lib loaded" << std::endl;
}

void Core::Core::restartGame() {
    _game.getInterface().restart();
    gameState = Core::GameState::GAME_LOOP;
    bindEvents();
}

void Core::Core::goToMenu() {
    gameState = Core::GameState::MENU_LOOP;
    bindEvents();
}

void Core::Core::closeGraphical() {
    _graphical.getWindowInterface().closeWindow();
    _graphical.getInterface().destroyRessource();
}
