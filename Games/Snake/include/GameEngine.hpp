/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameEngine
*/

#pragma once
#include "../../Interface/Game/IGames.hpp"
#include <array>
#include <ncurses.h>

class GameEngine
{
    public:
        GameEngine() = default;
        ~GameEngine() = default;

        void processGameTick(IClock &clock);

        IEvent::EventHandler &getEventBindings();

    private:
        IEvent::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();
        struct SnakePos {
                std::array<int, 101> x;
                std::array<int, 101> y;
                int size;
        };
        SnakePos snake_pos = {{0}, {0}, 0};
        void displaySnake(WINDOW *win, const SnakePos &snake);
        void displayGameOver(WINDOW *win, int score);
        bool checkGameStatus(const SnakePos &snake, int, int height);
        void updateSnakePosition(SnakePos &snake, int &stock_x, int &stock_y, int ch);
};
