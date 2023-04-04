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
#define PATH_FONT "./assets/PressStart2P.ttf"


class ClockSFML: public IClock {
private:
    sf::Clock clock;
    double time;

public:
    ClockSFML(): clock{sf::Clock()} {};
    ~ClockSFML() {};

    void startClock() override;

    double getTimeElapsed() override;

    void resetClock() override;

    void initClock() override;
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

    virtual void setPosition(int x, int y) final {(void)x;(void)y;};

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void updateCell(int x, int y, Color) final;
};

class TextSFML
    : public IText
{
private:
    sf::RenderWindow *_window;
    sf::Text _text;
    sf::Font _font;

public:
    TextSFML(sf::RenderWindow *window);
    ~TextSFML();

    //Entity
    virtual void create(std::string) final;

    virtual void setPosition(int x, int y) final;

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void changeString(std::string) final;
};

class GraphicalFactorySFML: public IGraphicalFactory {
public:
    GraphicalFactorySFML() {std::cout << "\tGraphicalFactorySFML instance create;" << std::endl; };
    ~GraphicalFactorySFML() {std::cout << "\tGraphicalFactorySFML instance destroy;" << std::endl;};

    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;
};