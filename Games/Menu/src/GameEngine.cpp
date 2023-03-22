/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#include "menu.hpp"

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

}

