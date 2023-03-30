/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalFactorySFML
*/

#pragma once
#include "../../../Interface/Graphical/IGraphicalFactory.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class ClockSFML: public IClock {
private:
        time_t time;

public:
    void startClock() override {};

    time_t getTimeElapsed() override { return 0; };

    void resetClock() override {};

    void initClock() override {};
};

class WindowSFML: public IWindow {
private:
    IWindow::EventHandler _eventBinding;
    sf::RenderWindow *_window;
    sf::Event event;

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


class GridSFML
    : public IGrid
{
private:
    IEntity::Color colorBackGround = IEntity::Color::Yellow;
    sf::RenderWindow *_window;
    sf::RenderTexture *_renderer;
    int _gridColumn = 0;
    int _gridRow = 0;

    void setColor(int x, int y, sf::Color color);

public:
    GridSFML(sf::RenderWindow *window) : _window{window} {};
    ~GridSFML() {}

    //Entity
    virtual void create(int width, int heigth) final;

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void updateCell(int x, int y, Color) final;
};

class TextSFML
    : public IText
{
private:
    sf::RenderWindow *_window;

public:
    TextSFML(sf::RenderWindow *window) : _window{window} {};
    ~TextSFML() {}
    //Entity
    virtual void create(std::string) final {};

    virtual void setPosition(int x, int y) final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    virtual void changeString(std::string) final {};
};

class GraphicalFactorySFML: public IGraphicalFactory {
public:
    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;
};