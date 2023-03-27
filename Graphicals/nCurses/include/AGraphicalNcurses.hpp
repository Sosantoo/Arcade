/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalNCurses
*/

#pragma once

#include "../../Interface/AGraphical.hpp"
#include <ncurses.h>
#include "ncurses.hpp"

struct GraphicalInfo {
    WINDOW *win;
    bool isOpen;
    int xMax;
    int yMax;

    GraphicalInfo()
        : win(nullptr)
        , isOpen(false)
        , xMax(0)
        , yMax(0)
    {}
};

class AGraphicalNcurses: public AGraphical<GraphicalInfo> {
private:
    void EventPool(int key);

public:
    AGraphicalNcurses(): AGraphical<GraphicalInfo>() {};
    ~AGraphicalNcurses() {};

    virtual void openWindow() final;
    virtual void initWindow(std::string name, std::pair<size_t, size_t> size) final;
    virtual void closeWindow() final;
    virtual bool windowIsOpen() final;
    virtual void clear() final;
    virtual void display() final;
};