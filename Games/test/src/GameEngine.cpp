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
    // std::cout << clock.getTimeElapsed() << " ";
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

IWindow::EventHandler &GameEngine::getEventBindings() {
    return (gameEvent = {
        {IWindow::EventType::UP_pressed, [this](){this->upKeyPress(); }},
        {IWindow::EventType::DOWN_pressed, [this](){this->downKeyPress(); }},
        {IWindow::EventType::LEFT_pressed, [this](){this->leftKeyPress(); }},
        {IWindow::EventType::RIGHT_pressed, [this](){this->rightKeyPress(); }},
    });
}
