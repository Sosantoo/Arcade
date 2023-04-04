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

    std::unique_ptr<IWindow> _window; // main Window

    // Game
    void LoadGame();
    void UnLoadGame();
    std::unique_ptr<IClock> _clock;
    std::unique_ptr<IGrid> _grid;
    std::unique_ptr<IText> _score;
    std::unique_ptr<IText> _time;

    // Menu
    void loadMenu();
    void UnloadMenu();
    std::unique_ptr<IText> _titleGame;
    std::unique_ptr<IText> _TextFirstGame;
    std::unique_ptr<IText> _TextSecondGame;
    std::unique_ptr<IText> _TextThirdGame;
    std::unique_ptr<IText> _TitleGraphic;
    std::unique_ptr<IText> _TextFirstGraphic;
    std::unique_ptr<IText> _TextSecondGraphic;
    std::unique_ptr<IText> _TextThirdGraphic;


public:
    GraphicalLib();
    ~GraphicalLib();

    Lib::lib _libDetails;

    void load(Lib::lib);
    IGraphicalFactory& getInterface();
    IWindow& getWindowInterface();

    // Game getter
    IClock& getClockInterface();
    IGrid& getGrid();
    IText& getScore();
    IText& getTime();

    // Menu getter
    IText& getTitleGame();
    std::array<std::reference_wrapper<IText>, 3> getGameSelector();
    IText& titleGraphic();
    std::array<std::reference_wrapper<IText>, 3> getGraphicSelector();
};
