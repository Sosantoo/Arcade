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

        virtual IEvent::EventHandler &getEventBinding() = 0;

        virtual void processGameTick(IClock &) = 0;

        virtual std::vector<IEntity> getEntity() = 0;

};
