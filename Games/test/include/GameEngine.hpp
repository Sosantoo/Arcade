/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#pragma once

class GameEngine {
    private:
        IWindow::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();

    public:
        GameEngine();
        ~GameEngine();

        void processGameTick(IClock &clock);

        IWindow::EventHandler &getEventBindings();
};
