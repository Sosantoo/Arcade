/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** EventHandler
*/

#include "EventHandler.hpp"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::upKeyPress() {
    std::cout << "[Game Engine] upKeyPress process" << std::endl;

};

void EventHandler::downKeyPress() {
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
};

void EventHandler::leftKeyPress() {
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
};

void EventHandler::rightKeyPress() {
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
};

IEvent::EventHandler &EventHandler::getEventBindings() {
    return (eventHandler = {
        {IEvent::EventType::UP_pressed, [this](){this->upKeyPress(); }},
        {IEvent::EventType::DOWN_pressed, [this](){this->downKeyPress(); }},
        {IEvent::EventType::LEFT_pressed, [this](){this->leftKeyPress(); }},
        {IEvent::EventType::RIGHT_pressed, [this](){this->rightKeyPress(); }},
    });

}