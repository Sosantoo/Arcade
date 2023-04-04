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
    : _libFileManager{LibFileManager("./lib")}
    , _gameLibsSelected{0}
    , _graphicsLibsSelected{0}
{
    restart();
}

void Menu::upKeyPress() {
    _gameLibsSelected++;
    if (_gameLibsSelected >= _gameLibs.size())
        _gameLibsSelected = 0;
}

void Menu::downKeyPress() {
    if (_gameLibsSelected <= 0)
        _gameLibsSelected = _gameLibs.size() - 1;
    else
        _gameLibsSelected--;
}

void Menu::leftKeyPress() {
    _graphicsLibsSelected++;
    if (_graphicsLibsSelected >= _graphicLibs.size())
        _graphicsLibsSelected = 0;
}

void Menu::rightKeyPress() {
    if (_graphicsLibsSelected <= 0)
        _graphicsLibsSelected = _graphicLibs.size() - 1;
    else
        _graphicsLibsSelected--;
}


IWindow::EventHandler &Menu::getEventBinding() {
    return (_gameEvent = {
        {IWindow::EventType::UP_pressed, [this]() { this->upKeyPress(); }},
        {IWindow::EventType::DOWN_pressed, [this]() { this->downKeyPress(); }},
        {IWindow::EventType::LEFT_pressed, [this]() { this->leftKeyPress(); }},
        {IWindow::EventType::RIGHT_pressed, [this]() { this->rightKeyPress(); }},
        {IWindow::EventType::RESTART, [this]() { this->restart(); }},
    });
}

void Menu::loadCoreActions(LambdaLoadingGraphicsByName, LambdaLoadingGameByName) {

}

std::string Menu::getLibGameName(size_t index) {
    size_t numGraphics = std::min(static_cast<int>(_gameLibs.size()), 3);
    std::string output = (index < numGraphics) ? _gameLibs[index].name : "";

    return (output == _gameLibs[_gameLibsSelected].name)
        ? "["+ output +"]"
        : " " + output;
}

std::string Menu::getLibGraphicsName(size_t index) {
    size_t numGraphics = std::min(static_cast<int>(_graphicLibs.size()), 3);
    std::string output = (index < numGraphics) ? _graphicLibs[index].name : "";

    return (output == _graphicLibs[_graphicsLibsSelected].name)
        ? "["+ output +"]"
        : " " + output;
}

void Menu::displayTexts(
    IText &titleGame,
    IText &titleGraphic,
    std::array<std::reference_wrapper<IText>, 3>gameSelector,
    std::array<std::reference_wrapper<IText>, 3> graphicSelector
) {

    titleGame.changeString("Game libaries:");
    titleGraphic.changeString("Graphicals libaries:");
    titleGame.displayEntity();
    titleGraphic.displayEntity();

    for (int i = 0; i < 3; i++) {
        gameSelector[i].get().changeString(
            getLibGameName(i)
        );
        graphicSelector[i].get().changeString(
            getLibGraphicsName(i)
        );
        gameSelector[i].get().displayEntity();
        graphicSelector[i].get().displayEntity();
    }
}


bool Menu::processMenuTick(
    IText &titleGame,
    IText &titleGraphic,
    std::array<std::reference_wrapper<IText>, 3>gameSelector,
    std::array<std::reference_wrapper<IText>, 3> graphicSelector
) {
    displayTexts(titleGame, titleGraphic, gameSelector, graphicSelector);
    return true;
}

void Menu::restart() {
    _gameLibs = _libFileManager.getGameLibs();
    _graphicLibs = _libFileManager.getGraphicsLibs();
}
