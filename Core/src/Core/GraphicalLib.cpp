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
    _window.reset();

    UnLoadGame();
    UnloadMenu();
}

void GraphicalLib::load(Lib::lib libDetails) {
    std::cout << "[CORE] try to load: " << libDetails.name << std::endl;
    _libDetails = libDetails;
    _currentLib.load(libDetails, Lib::_GRAPHICALS_);

    //reset
    _window.reset();
    UnLoadGame();
    UnloadMenu();

    //init
    _currentLib.getInterface().loadResource();
    _window = _currentLib.getInterface().createWindow("arcade" + libDetails.name, 800, 800);
    LoadGame();
    loadMenu();
}

void GraphicalLib::LoadGame() {
    _clock = _currentLib.getInterface().createIClock();

    _grid = _window->createIGrid();
    _grid->create(50, 50);

    _score = _window->createIText();
    _score->create("Score: ");
    _score->setPosition(30, 90);

    _time = _window->createIText();
    _time->create("Time: ");
    _time->setPosition(30, 30);
};

void GraphicalLib::UnLoadGame() {
    _clock.reset();
    _grid.reset();
    _score.reset();
    _time.reset();
};

void GraphicalLib::loadMenu() {
    int leftPaddingTitle = 40;
    int leftPaddingItem = 120;
    int spacerItem = 70;
    int firstSection = 30;
    int SecondSection = 450;

    _TitleGraphic = _window->createIText();
    _TitleGraphic->create("_TitleGraphic");
    _TitleGraphic->setPosition(leftPaddingTitle, firstSection);

    _TextFirstGraphic = _window->createIText();
    _TextFirstGraphic->create("_TextFirstGraphic");
    _TextFirstGraphic->setPosition(leftPaddingItem, firstSection + spacerItem * 1);

    _TextSecondGraphic = _window->createIText();
    _TextSecondGraphic->create("_TextSecondGraphic");
    _TextSecondGraphic->setPosition(leftPaddingItem, firstSection + spacerItem * 2);

    _TextThirdGraphic = _window->createIText();
    _TextThirdGraphic->create("_TextThirdGraphic");
    _TextThirdGraphic->setPosition(leftPaddingItem, firstSection + spacerItem * 3);

    _titleGame= _window->createIText();
    _titleGame->create("_titleGame");
    _titleGame->setPosition(leftPaddingTitle, SecondSection);

    _TextFirstGame = _window->createIText();
    _TextFirstGame->create("_TextFirstGame");
    _TextFirstGame->setPosition(leftPaddingItem, SecondSection + spacerItem * 1);

    _TextSecondGame = _window->createIText();
    _TextSecondGame->create("_TextSecondGame");
    _TextSecondGame->setPosition(leftPaddingItem, SecondSection + spacerItem * 2);

    _TextThirdGame = _window->createIText();
    _TextThirdGame->create("_TextThirdGame");
    _TextThirdGame->setPosition(leftPaddingItem, SecondSection + spacerItem * 3);
};

void GraphicalLib::UnloadMenu() {
    _TitleGraphic.reset();
    _TextFirstGraphic.reset();
    _TextSecondGraphic.reset();
    _TextThirdGraphic.reset();

    _titleGame.reset();
    _TextFirstGame.reset();
    _TextSecondGame.reset();
    _TextThirdGame.reset();
};


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

IText& GraphicalLib::getTitleGame() {
    return *_titleGame;
}

std::array<std::reference_wrapper<IText>, 3> GraphicalLib::getGameSelector() {
    return {
        std::ref(*_TextFirstGame),
        std::ref(*_TextSecondGame),
        std::ref(*_TextThirdGame)
    };
}

IText& GraphicalLib::titleGraphic() {
    return *_TitleGraphic;
}

std::array<std::reference_wrapper<IText>, 3> GraphicalLib::getGraphicSelector() {
    return {
        std::ref(*_TextFirstGraphic),
        std::ref(*_TextSecondGraphic),
        std::ref(*_TextThirdGraphic)
    };
}

