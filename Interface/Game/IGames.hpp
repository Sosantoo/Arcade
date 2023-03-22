/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGames
*/

#pragma once
#include "../Graphical/IGraphicals.hpp"

class IGame {
    public:
        ~IGame() = default;

        virtual void start(IGraphical &, IEvent::EventHandler &) = 0;

        virtual void stop() = 0;

        virtual void restart() = 0;
};

typedef IGame* create_game_t();
typedef void destroy_game_t(IGame *);
