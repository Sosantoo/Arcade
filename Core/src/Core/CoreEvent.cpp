/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreEvent
*/

#include "Core/Core.hpp"
#include "Exceptions/Exceptions.hpp"
#include <iostream>

void Core::Core::tearDownGraphics() {
    _graphical.getWindowInterface().closeWindow();
    _graphical.getInterface().destroyRessource();
}

void Core::Core::nextGraphicsLibrary() {
    tearDownGraphics();

    _graphical._libDetails = _libFileManager.getNextGraphicalsLib(_graphical._libDetails);
    _graphical.load(_graphical._libDetails);
    bindEvents();
    std::cout << "[CORE] " << _graphical._libDetails.name << " lib loaded" << std::endl;
}

void Core::Core::nextGameLibrary() {
    _game._libDetails = _libFileManager.getNextGameLib(_game._libDetails);
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

void Core::Core::launchFromMenu(std::string gameLibName, std::string graphicLibName) {
    gameState = Core::GameState::GAME_LOOP;
    Lib::lib gameLibDetailsFound = _libFileManager.getLibByName(gameLibName);
    Lib::lib graphicLibDetailsFound = _libFileManager.getLibByName(graphicLibName);

    if (!(_game._libDetails == gameLibDetailsFound)) {
        _game.load(gameLibDetailsFound);
    }
    if (!(_graphical._libDetails == graphicLibDetailsFound)) {
        tearDownGraphics();
        _graphical.load(graphicLibDetailsFound);
    }
    bindEvents();
    std::cout << "[CORE] running: " << _game._libDetails.name << " on " << _graphical._libDetails.name << std::endl;
}

void Core::Core::goToMenu() {
    gameState = Core::GameState::MENU_LOOP;
    bindEvents();
}

void Core::Core::closeGraphical() {
    _graphical.getWindowInterface().closeWindow();
    _graphical.getInterface().destroyRessource();
}
