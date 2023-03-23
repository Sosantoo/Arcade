/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#include "test.hpp"

GameEngine::GameEngine(IGraphical &graphical)
    : EventHandler(graphical),
    _graphical{graphical}
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::GameEngineLoop()
{
    _graphical.openWindow();
    while (_graphical.windowIsOpen()) {
        _graphical.clear();
        _graphical.display();
        //_graphical.loadEventBindings();
    }
}
