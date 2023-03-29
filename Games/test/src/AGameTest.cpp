/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#include "AGameTest.hpp"
#include <iostream>

IWindow::EventHandler &AGameTest::getEventBinding()
{
    return (gameEvent = {
                {IWindow::EventType::UP_pressed,
                 [this]() {
                     this->upKeyPress();
                 }},
                {IWindow::EventType::DOWN_pressed,
                 [this]() {
                     this->downKeyPress();
                 }},
                {IWindow::EventType::LEFT_pressed,
                 [this]() {
                     this->leftKeyPress();
                 }},
                {IWindow::EventType::RIGHT_pressed,
                 [this]() {
                     this->rightKeyPress();
                 }},
            });
};

void AGameTest::upKeyPress()
{
    std::cout << "[Game Engine] upKeyPress process" << std::endl;
};

void AGameTest::downKeyPress()
{
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
};

void AGameTest::leftKeyPress()
{
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
};

void AGameTest::rightKeyPress()
{
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
};

void AGameTest::processGameTick(IClock &clock){
};

std::vector<IEntity> AGameTest::getEntity()
{

    return {};
};
