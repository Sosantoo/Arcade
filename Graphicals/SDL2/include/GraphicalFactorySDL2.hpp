/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalFactorySDL2
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

    time_t getTimeElapsed() override {};

    void resetClock() override {};

    void initClock() override {};

    IClock &getClock()override {};
};

class WindowSDL2: public IWindow {
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

class GridSDL2
    : public IGrid
{
public:
    //Entity
    virtual void create() final {};

    virtual void setSize(int width, int heigth) final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};


    virtual void updateCell(int x, int y, Color) final {};
};

class TextSDL2
    : public IText
{
public:
    //Entity
    virtual void create() final {};

    virtual void setSize(int width, int heigth) final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    virtual void changeString(std::string str) final {};
};

class GraphicalFactorySDL2: public IGraphicalFactory {
public:
    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;

    std::unique_ptr<IEntity> createIEntity(IEntity::EntityType type) final;
};
