/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#include "Core/Core.hpp"
#include "Exceptions/Exceptions.hpp"
#include <iostream>
#include <unistd.h>

Core::Core::Core(const std::string &SharedLibPath)
    : _LibFileManager{LibFileManager(SharedLibPath)}
    , gameState{Core::GameState::MENU_LOOP}
{
}

Core::Core::~Core()
{
}

void Core::Core::init(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    if (!_LibFileManager.isAvailable(GraphicalsLibPath) || !_LibFileManager.isAvailable(GameLibPath)) {
        throw CoreExceptions::LibUnknowExceptions(GraphicalsLibPath + " or " + GameLibPath);
    }

    _LibFileManager.displayavailableLib();

    _game.load(_LibFileManager.getLibBypath(GameLibPath));
    _graphical.load(_LibFileManager.getLibBypath(GraphicalsLibPath));
    _menu.load(_LibFileManager.getLibByName("arcade_menu.so"));
    bindEvents();
}

void Core::Core::bindEvents() {
    coreEventBindings = {
        {IWindow::EventType::NEXT_LIB, [this](){ this->nextGraphicsLibrary(); }},
        {IWindow::EventType::NEXT_GAME, [this](){ this->nextGameLibrary(); }},
        {IWindow::EventType::RESTART, [this](){ this->restartGame(); }},
        {IWindow::EventType::GO_TO_MENU, [this](){ this->goToMenu(); }},
        {IWindow::EventType::QUIT, [this](){ this->closeGraphical(); }},
    };

    //core Event bindings
    _graphical.getWindowInterface().loadEventBindings(
        coreEventBindings
    );
    //Game Event bindings
    _graphical.getWindowInterface().loadEventBindings(
        gameState == Core::GameState::GAME_LOOP
            ? _game.getInterface().getEventBinding()
            : _menu.getInterface().getEventBinding()
    );
}

void Core::Core::loopMenu() {
    _menu.getInterface().processMenuTick(
        _graphical.getTitleGame(),
        _graphical.titleGraphic(),
        _graphical.getGameSelector(),
        _graphical.getGraphicSelector()
    );
}

void Core::Core::loopGame() {
    _game.getInterface().processGameTick(
        _graphical.getGrid(),
        _graphical.getScore(),
        _graphical.getTime(),
        _graphical.getClockInterface()
    );
}

void Core::Core::launch() {
    while(_graphical.getWindowInterface().windowIsOpen()) {
        _graphical.getWindowInterface().clear();
        _graphical.getWindowInterface().eventPollEvent();

        switch (gameState) {
            case Core::GameState::MENU_LOOP: loopMenu(); break;
            case Core::GameState::GAME_LOOP: loopGame(); break;
        }

         _graphical.getWindowInterface().display();
    }
}

int coreEntryPoint(const std::string &graphicalPathLib)
{
    Core::Core core("./lib/");
    core.init(graphicalPathLib, "./lib/arcade_snake.so");
    core.launch();
    return 0;
}
