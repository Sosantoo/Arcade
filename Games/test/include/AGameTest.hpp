/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#pragma once
#include "../../Interface/AGame.hpp"

class AGameTest : public AGame
{
    private:
        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();
        IWindow::EventHandler gameEvent;

    public:
        AGameTest() = default;
        ~AGameTest() = default;

        IWindow::EventHandler &getEventBinding() final;
        bool processGameTick(IGrid &, IText &, IText &, IClock &) final;
        void restart() final;
};
