/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#pragma once
#include "../../Interface/Game/IGames.hpp"

class GameEngine
{
    private:
        IEvent::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();

    public:
        GameEngine();
        ~GameEngine();

        void processGameTick(IClock &clock);

        IEvent::EventHandler &getEventBindings();
};
