/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#include "Core/Core.hpp"
#include "Exceptions/Exceptions.hpp"
#include <iostream>

Core::Core::Core(const std::string &SharedLibPath)
    : _LibFileManager{LibFileManager(SharedLibPath)}
{
}

Core::Core::~Core()
{
}

void Core::Core::init(const std::string GraphicalsLibPath, const std::string GameLibPath) {
    if (!_LibFileManager.isAvailable(GraphicalsLibPath) ||
    !_LibFileManager.isAvailable(GameLibPath))
    {
        throw CoreExceptions::LibUnknowExceptions(GraphicalsLibPath + " or " + GameLibPath);
    }
    _game.load(_LibFileManager.getLibBypath(GameLibPath));
    _graphical.load(_LibFileManager.getLibBypath(GraphicalsLibPath));
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
        _game.getInterface().getEventBinding()
    );
}

void Core::Core::launchGame() {
    bool gameOver = false;
    bindEvents();

    while(_graphical.getWindowInterface().windowIsOpen() && !gameOver) {
        _graphical.getWindowInterface().eventPollEvent();
        _graphical.getWindowInterface().clear();
        _graphical.display();
        gameOver = _game.getInterface().processGameTick(
            _graphical.getGrid(),
            _graphical.getScore(),
            _graphical.getTime(),
            _graphical.getClockInterface()
        );
        _graphical.getWindowInterface().display();
    }
}

int coreEntryPoint(const std::string &graphicalPathLib)
{
    Core::Core core("./lib/");
    core.init(graphicalPathLib, "./lib/arcade_snake.so");
    core.launchGame();
    return 0;
}
