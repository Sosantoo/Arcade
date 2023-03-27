/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#include "test.hpp"

void AGameTest::start(IGraphical &graphical, IEvent::EventHandler &coreEvent) {
    _coreEvent = coreEvent;
    _graphical = &graphical;
    std::cout << "[GAME test] start" << std::endl;
    if (_graphical == nullptr)
        return;
    // _graphical->initWindow("test game", {600, 600});
    // _graphical->loadEventBindings(gameEngine.getEventBindings());
    _graphical->loadEventBindings(_coreEvent);

    // gameEngine->GameEngineLoop();
};

void AGameTest::stop() {
    std::cout << "[GAME test] stop" << std::endl;
};

void AGameTest::restart() {
    std::cout << "[GAME test] restart" << std::endl;
};