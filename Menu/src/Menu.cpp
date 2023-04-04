/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "Menu.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>


Menu::Menu()
{

}

void Menu::upKeyPress() {

}

void Menu::downKeyPress() {

}

void Menu::leftKeyPress() {

}

void Menu::rightKeyPress() {
    std::cout << "right" << std::endl;
}


IWindow::EventHandler &Menu::getEventBinding() {
    return (gameEvent = {
        {IWindow::EventType::UP_pressed, [this]() { this->upKeyPress(); }},
        {IWindow::EventType::DOWN_pressed, [this]() { this->downKeyPress(); }},
        {IWindow::EventType::LEFT_pressed, [this]() { this->leftKeyPress(); }},
        {IWindow::EventType::RIGHT_pressed, [this]() { this->rightKeyPress(); }},
        {IWindow::EventType::RESTART, [this]() { this->restart(); }},
    });
}

void Menu::loadCoreActions(LambdaLoadingGraphicsByName, LambdaLoadingGameByName) {

}

bool Menu::processMenuTick(IText &, IText &, std::array<std::reference_wrapper<IText>, 3>, std::array<std::reference_wrapper<IText>, 3>) {
    return true;
}

void Menu::restart() {

}
