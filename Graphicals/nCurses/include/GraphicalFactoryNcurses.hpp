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
    WINDOW *_window;
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

    std::unique_ptr<IText> createIText() final;

    std::unique_ptr<IGrid> createIGrid() final;
};

class GridNcurses
    : public IGrid
{
private:
    WINDOW *_window;
    int _gridRow;
    int _gridColumn;
    int colorBackGround;
    void setColorPair(int colorPair, int foregroundColor, int backgroundColor);
    void setColor(int x, int y, int color);

public:
    GridNcurses(WINDOW *window) : _window{window} {};
    ~GridNcurses() {};
    //Entity
    virtual void create(int width, int heigth) final;

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void updateCell(int x, int y, Color) final;
};

class TextNcurses
    : public IText
{
private:
    WINDOW *_window;

public:
    TextNcurses(WINDOW *window) : _window{window} {};
    ~TextNcurses() {};
    //Entity
    virtual void create(std::string) final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    virtual void changeString(std::string) final {};
};

class GraphicalFactoryNcurses: public IGraphicalFactory {
public:
    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;
};

