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
        WINDOW *window{};
        bool isOpen{false};
        int x{0};
        int y{0};
        int xMax{0};
        int yMax{0};
};

class AGraphicalNcurses : public AGraphical<GraphicalInfo>
{
    public:
        AGraphicalNcurses();
        ~AGraphicalNcurses();

        // base
        void loadResource() override;
        void destroyRessource() override;

        // Iwindow
        void openWindow();
        void initWindow(std::string name, std::pair<size_t, size_t> size) override;
        void closeWindow() override;
        bool windowIsOpen() override;
        void clear() override;
        void display() override;

        // IEvent
        void eventPollEvent() override;

        // Clock
        IClock &getClock() override;
};
