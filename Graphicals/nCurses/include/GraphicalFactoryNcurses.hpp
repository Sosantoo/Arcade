/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalFactory
*/

#pragma once
#include "../../../Interface/Graphical/IGraphicalFactory.hpp"
#include <iostream>
#include <curses.h>

class ClockNcurses: public IClock {
private:
        time_t time;

public:
    void startClock() override {};

    time_t getTimeElapsed() override { return 0; };

    void resetClock() override {};

    void initClock() override {};
};

class WindowNcurses: public IWindow {
private:
    IWindow::EventHandler _eventBinding;
    WINDOW *window;
    bool isOpen;
    int xMax;
    int yMax;

public:
    void initWindow(std::string name, size_t width, size_t height) final;

    void closeWindow() final;

    bool windowIsOpen() final;

    void clear() final;

    void display() final;

    void callEvent(const IWindow::EventType) final;

    void loadEventBindings(EventHandler &) final;

    void eventPollEvent() final;
};

class GridNcurses
    : public IGrid
{
public:
    //Entity
    virtual void create(int width, int heigth) final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    virtual void updateCell(int x, int y, Color) final {};
};

class TextNcurses
    : public IText
{
public:
    //Entity
    virtual void create() final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    virtual void changeString(std::string str) final {};
};

class GraphicalFactoryNcurses: public IGraphicalFactory {
public:
    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;

    std::unique_ptr<IText> createIText() final;

    std::unique_ptr<IGrid> createIGrid() final;
};

