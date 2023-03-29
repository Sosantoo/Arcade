/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "AGameSnake.hpp"
#include <iostream>

void GameEngine::displayGameOver(WINDOW *win, int score) {}
bool GameEngine::checkGameStatus(const SnakePos &snake, int, int height) {}
void GameEngine::updateSnakePosition(SnakePos &snake, int &stock_x, int &stock_y, int ch) {}

void GameEngine::processGameTick(IClock &clock){
    // std::cout << clock.getTimeElapsed() << " ";
};

void GameEngine::upKeyPress()
{
    std::cout << "[Game Engine] upKeyPress process" << std::endl;
};

void GameEngine::downKeyPress()
{
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
};

void GameEngine::leftKeyPress()
{
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
};

void GameEngine::rightKeyPress()
{
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
};

IEvent::EventHandler &GameEngine::getEventBindings()
{
    return (gameEvent = {
                {IEvent::EventType::UP_pressed,
                 [this]() {
                     this->upKeyPress();
                 }},
                {IEvent::EventType::DOWN_pressed,
                 [this]() {
                     this->downKeyPress();
                 }},
                {IEvent::EventType::LEFT_pressed,
                 [this]() {
                     this->leftKeyPress();
                 }},
                {IEvent::EventType::RIGHT_pressed,
                 [this]() {
                     this->rightKeyPress();
                 }},
            });
}

// pour game
// mvwprintw(graphicalInfo.win, 1, graphicalInfo.xMax / 3 - 15, "Arcade");