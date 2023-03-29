/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "AGameSnake.hpp"
#include <iostream>

void AGameSnake::displayGameOver(WINDOW *win, int score) {}
bool AGameSnake::checkGameStatus(const SnakePos &snake, int, int height) {}
void AGameSnake::updateSnakePosition(SnakePos &snake, int &stock_x, int &stock_y, int ch) {}

void AGameSnake::upKeyPress()
{
    std::cout << "[Game Engine] upKeyPress process" << std::endl;
};

void AGameSnake::downKeyPress()
{
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
};

void AGameSnake::leftKeyPress()
{
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
};

void AGameSnake::rightKeyPress()
{
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
};

IEvent::EventHandler &AGameSnake::getEventBinding()
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

void AGameSnake::processGameTick(IClock &clock){};

std::vector<IEntity> AGameSnake::getEntity()
{
    return {};
};

// pour game
// mvwprintw(graphicalInfo.win, 1, graphicalInfo.xMax / 3 - 15, "Arcade");