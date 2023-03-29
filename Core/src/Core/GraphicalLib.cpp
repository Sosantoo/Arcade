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
    _previousLib = _currentLib.getInterfacePtr();

    std::cout << "[CORE] " << libDetails.name << std::endl;
    _currentLib.load(libDetails, Lib::_GRAPHICALS_);

    _window.reset();
    _clock.reset();
    _grid.reset();
    _score.reset();
    _time.reset();

    _window = _currentLib.getInterface().createWindow("arcade", 800, 800);
    _grid = _currentLib.getInterface().createIEntity(IEntity::EntityType::GridEntity);
    _score = _currentLib.getInterface().createIEntity(IEntity::EntityType::TextEntity);
    _score = _currentLib.getInterface().createIEntity(IEntity::EntityType::TextEntity);
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

IEntity& GraphicalLib::getEntity() {
    return *_grid;
}
