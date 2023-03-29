/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphicalNCurses
*/

#pragma once

#include "../../Interface/AGraphical.hpp"
#include <ncurses.h>
#include <ostream>

struct GraphicalInfo {
        WINDOW *win{};
        bool isOpen{false};
        int xMax{0};
        int yMax{0};
};

class AGraphicalNcurses : public AGraphical<GraphicalInfo>
{
    public:
        AGraphicalNcurses();
        ~AGraphicalNcurses();

        // base
        void loadResource() final;
        void destroyRessource() final;

        // Iwindow
        void openWindow();
        void initWindow(std::string name, std::pair<size_t, size_t> size) final;
        void closeWindow() final;
        bool windowIsOpen() final;
        void clear() final;
        void display() final;

        // IEvent
        void eventPollEvent() final;

        // Clock
        IClock &getClock() final;

    private:
};
