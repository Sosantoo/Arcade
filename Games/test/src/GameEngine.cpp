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
    while (_graphical.windowIsOpen()) {
        _graphical.display();
    }
}

