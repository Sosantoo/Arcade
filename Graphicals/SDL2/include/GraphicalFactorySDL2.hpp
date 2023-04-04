/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GraphicalFactorySDL2
*/

#pragma once
#include "../../../Interface/Graphical/IGraphicalFactory.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#define PATH_FONT "./assets/PressStart2P.ttf"
class ClockSDL2 : public IClock {
private:
    Uint32 startTime;

public:
    void startClock() override;

    double getTimeElapsed() override;

    void resetClock() override;

    void initClock() override;
};


class WindowSDL2: public IWindow {
private:
    IWindow::EventHandler _eventBinding;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    SDL_Event event;
    bool isOpen;

public:
    void initWindow(std::string name, size_t width, size_t height) final;

    void closeWindow() final;

    bool windowIsOpen() final;

    void clear() final;

    void display() final;

    void callEvent(const IWindow::EventType) final;

    void loadEventBindings(EventHandler &) final;

    void eventPollEvent() final;

    std::unique_ptr<IText> createIText() final ;

    std::unique_ptr<IGrid> createIGrid() final ;
};


class GridSDL2 : public IGrid {
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    int _gridColumn, _gridRow;
    IEntity::Color colorBackGround = IEntity::Color::Yellow;

    void resetColor();
    void setColor(int x, int y, SDL_Color color);

public:
    GridSDL2(SDL_Window *window, SDL_Renderer *renderer) : _window{window}, _renderer{renderer} {};
    ~GridSDL2() {}

    virtual void create(int gridRow, int gridColumn) final;

    virtual void setPosition(int x, int y) final { (void)x; (void)y; };

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void updateCell(int x, int y, Color color) final;
};


class TextSDL2
    : public IText
{
private:
    SDL_Renderer *_renderer;
    SDL_Surface * _surface;
    SDL_Texture *_text_texture;
    TTF_Font *_font;
    SDL_Rect _rect;

public:
    TextSDL2(SDL_Renderer *renderer);
    ~TextSDL2();

    virtual void create(std::string str) final;

    virtual void setPosition(int x, int y) final;

    virtual void destroy() final;

    virtual void displayEntity() final;

    virtual void changeString(std::string str) final;
};


class GraphicalFactorySDL2: public IGraphicalFactory {
public:
    GraphicalFactorySDL2() {std::cout << "\tGraphicalFactorySDL2 instance create;" << std::endl; };
    ~GraphicalFactorySDL2() {std::cout << "\tGraphicalFactorySDL2 instance destroy;" << std::endl;};

    void loadResource() final;

    void destroyRessource() final;

    std::unique_ptr<IClock> createIClock() final;

    std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) final;
};
