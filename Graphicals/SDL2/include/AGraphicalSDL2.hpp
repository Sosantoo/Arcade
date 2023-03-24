/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalSDL2
*/

#pragma once
#include "../../Interface/AGraphical.hpp"
#include "sdl2.hpp"

struct GraphicalInfo {
    SDL_Window *window;
    SDL_Event event;
    bool isOpen;

    GraphicalInfo()
        : window(nullptr)
        , event({})
        , isOpen(false)
    {}
};

class AGraphicalSDL2: public AGraphical<GraphicalInfo> {
public:
    AGraphicalSDL2(): AGraphical<GraphicalInfo>() {};
    ~AGraphicalSDL2() {};

    virtual void openWindow() final;
    virtual void initWindow(std::string name, std::pair<size_t, size_t> size) final;
    virtual void closeWindow() final;
    virtual bool windowIsOpen() final;
    virtual void clear() final;
    virtual void display() final;
};
