/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameWrapper
*/

#include "test.hpp"

void AGameWrapper::start() {
    std::cout << "[GAME test] start" << std::endl;
    _graphical.initWindow("test game", {600, 600});
    _graphical.loadEventBindings(gameEngine->getEventBindings());
    _graphical.loadEventBindings(_coreEvent);

    gameEngine->GameEngineLoop();
};

void AGameWrapper::stop() {
    std::cout << "[GAME test] stop" << std::endl;
};

void AGameWrapper::restart() {
    std::cout << "[GAME test] restart" << std::endl;
};
