/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGame
*/

#pragma once
#include "../Graphical/IGraphicalFactory.hpp"

class IGame {
    public:
        ~IGame() = default;

        virtual IWindow::EventHandler &getEventBinding() = 0;

        virtual bool processGameTick(IGrid &, IText &, IText &, IClock &) = 0;

        virtual void restart() = 0;
};
