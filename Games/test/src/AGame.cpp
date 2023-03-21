/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#include "test.hpp"

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

void AGameWrapper::start() {
    std::cout << "[Game test] start" << std::endl;

    _graphical.initWindow("myTestWindow", {800, 800});
    _graphical.openWindow();
    gameEngine->GameEngineLoop();
};

void AGameWrapper::stop() {
    std::cout << "[Game test] stop" << std::endl;
};

void AGameWrapper::reset() {
    std::cout << "[Game test] reset" << std::endl;
};
