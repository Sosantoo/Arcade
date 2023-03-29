/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalLib
*/

#pragma once
#include "lib/LibHandler.hpp"
#include "lib/LibFileManager.hpp"
#include "interface.hpp"

class GraphicalLib {
private:
    std::unique_ptr<IGraphicalFactory> _previousLib;
    LibHandler<IGraphicalFactory> _currentLib;
    std::unique_ptr<IWindow> _window;
    std::unique_ptr<IClock> _clock;
    std::unique_ptr<IEntity> _grid;
    std::unique_ptr<IEntity> _score;
    std::unique_ptr<IEntity> _time;

public:
    GraphicalLib();
    ~GraphicalLib();

    Lib::lib _libDetails;
    void load(Lib::lib);
    IGraphicalFactory& getInterface();
    IWindow& getWindowInterface();
    IClock& getClockInterface();
    IEntity& getEntity();
};
