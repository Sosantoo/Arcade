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
    LibHandler<IGraphicalFactory> _currentLib;
    std::unique_ptr<IWindow> _window;
    std::unique_ptr<IClock> _clock;
    std::unique_ptr<IGrid> _grid;
    std::unique_ptr<IText> _score;
    std::unique_ptr<IText> _time;

public:
    GraphicalLib();
    ~GraphicalLib();

    Lib::lib _libDetails;
    void load(Lib::lib);
    void display();
    IGraphicalFactory& getInterface();
    IWindow& getWindowInterface();
    IClock& getClockInterface();
    IGrid& getGrid();
    IText& getScore();
    IText& getTime();

};
