/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#include "AGameTest.hpp"
#include <iostream>

IEvent::EventHandler &AGameTest::getEventBinding()
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
