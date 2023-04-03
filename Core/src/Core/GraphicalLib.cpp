/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalLib
*/

#include "Core/GraphicalLib.hpp"
#include <iostream>

GraphicalLib::GraphicalLib()
    : _window{nullptr}
    , _clock{nullptr}
    , _grid{nullptr}
    , _score{nullptr}
    , _time{nullptr}
{
}

GraphicalLib::~GraphicalLib()
{
    _time.reset();
    _score.reset();
    _grid.reset();
    _window.reset();
}

void GraphicalLib::load(Lib::lib libDetails) {
    std::cout << "[CORE] try to load: " << libDetails.name << std::endl;
    _libDetails = libDetails;
    _currentLib.load(libDetails, Lib::_GRAPHICALS_);

    _window.reset();
    _clock.reset();
    _grid.reset();
    _score.reset();
    _time.reset();

    _currentLib.getInterface().loadResource();
    _window = _currentLib.getInterface().createWindow("arcade" + libDetails.name, 800, 800);
    _clock = _currentLib.getInterface().createIClock();
    _grid = _window->createIGrid();
    _score = _window->createIText();
    _time = _window->createIText();

    _grid->create(50, 50);
    _score->create("Score: ");
    _score->setPosition(30, 90);

    _time->create("Time: ");
    _score->setPosition(30, 30);
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
