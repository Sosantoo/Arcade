/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#include "AGame.hpp"

AGameWrapper::AGameWrapper(IGraphical &graphical, IEvent::EventHandler &coreEvent):
    _graphical{graphical},
    _coreEvent{coreEvent}
{
    gameEngine = std::make_shared<GameEngine>(_graphical);
    _graphical.loadEventBindings(gameEngine->getEventBindings());
}

AGameWrapper::~AGameWrapper()
{
}
