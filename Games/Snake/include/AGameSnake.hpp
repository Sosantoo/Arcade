/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include <curses.h>

class AGameSnake : public AGame
{
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

    public:
        AGameSnake() = default;
        AGameSnake(IGraphicalFactory &, IWindow::EventHandler &){};
        ~AGameSnake() = default;
        IEvent::EventHandler &getEventBinding() override;
        void processGameTick(IClock &clock) override;
        std::vector<IEntity> getEntity() override;
};