/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalLib
*/

#include "Core/GraphicalLib.hpp"
#include <iostream>

GraphicalLib::GraphicalLib()
    : _previousLib{nullptr}
    , _window{nullptr}
    , _clock{nullptr}
    , _grid{nullptr}
    , _score{nullptr}
    , _time{nullptr}
{
}

GraphicalLib::~GraphicalLib()
{
}

void GraphicalLib::load(Lib::lib libDetails) {
    _previousLib.reset();
    _previousLib = std::move(_currentLib.getInterfacePtr());

    std::cout << "[CORE] next graphics: " << libDetails.name << std::endl;
    _libDetails = libDetails;
    _currentLib.load(libDetails, Lib::_GRAPHICALS_);

    _window.reset();
    _clock.reset();
    _grid.reset();
    _score.reset();
    _time.reset();

    _currentLib.getInterface().loadResource();
    _window = _currentLib.getInterface().createWindow("arcade" + libDetails.name, 800, 800);
    _grid = _window->createIGrid();
    _score = _window->createIText();
    _time = _window->createIText();

    _grid->create(50, 50);
    _score->create("test");
    _time->create("test");
    std::cout << "loaded " << libDetails.name << std::endl;
}

void GraphicalLib::display() {
    _grid->displayEntity();
    _score->displayEntity();
    _time->displayEntity();
}

void GraphicalLib::test() {
    _grid->updateCell(0, 0, IEntity::Color::Green);
    _grid->updateCell(19, 19, IEntity::Color::Green);
}

void GraphicalLib::test2() {
    _grid->updateCell(0, 0, IEntity::Color::Blue);
    _grid->updateCell(19, 19, IEntity::Color::Blue);
}

IGraphicalFactory& GraphicalLib::getInterface() {
    return _currentLib.getInterface();
}

IWindow& GraphicalLib::getWindowInterface() {
    return *_window;
}

IClock& GraphicalLib::getClockInterface() {
    return *_clock;
}


IGrid& GraphicalLib::getGrid() {
    return *_grid;
}

IText& GraphicalLib::getScore() {
    return *_score;
}

IText& GraphicalLib::getTime() {
    return *_time;
}
