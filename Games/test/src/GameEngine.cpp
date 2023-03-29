/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#include "test.hpp"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::processGameTick(IClock &clock) {
    //std::cout << clock.getTimeElapsed() << " ";
};

void GameEngine::upKeyPress() {
    std::cout << "[Game Engine] upKeyPress process" << std::endl;

};

void GameEngine::downKeyPress() {
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
};

void GameEngine::leftKeyPress() {
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
};

void GameEngine::rightKeyPress() {
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
};

IEvent::EventHandler &GameEngine::getEventBindings() {
    return (gameEvent = {
        {IEvent::EventType::UP_pressed, [this](){this->upKeyPress(); }},
        {IEvent::EventType::DOWN_pressed, [this](){this->downKeyPress(); }},
        {IEvent::EventType::LEFT_pressed, [this](){this->leftKeyPress(); }},
        {IEvent::EventType::RIGHT_pressed, [this](){this->rightKeyPress(); }},
    });
}
