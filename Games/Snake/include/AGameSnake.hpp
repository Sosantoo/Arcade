/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include <curses.h>
#define INITIAL_LENGTH 3;



class AGameSnake : public AGame
{
    private:
        int width;
        int height;
        const char empty = ' ';
        const char wall = 'W';
        const char snake = '#';
        const char food = '*';
        const int initialLength = 10;
        bool gameOver;
        int dx = 1; // horizontal movement direction
        int dy = 0; // vertical movement direction
        int score = 0;
        int foodX = 0;
        int foodY = 0;

        std::vector<std::vector<char>> _board;
        std::vector<std::pair<int, int>> _snakeCoords;

        void generateFood();
        void clearBoard();
        void drawnSnake();
        void drawnFood();
        void displayBoard(IGrid &);
        void moveAllSnake();

        IWindow::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();



    public:
        AGameSnake();
        AGameSnake(IGraphicalFactory &, IWindow::EventHandler &){};
        ~AGameSnake() = default;
        IWindow::EventHandler &getEventBinding() override;
        bool processGameTick(IGrid &, IText &, IText &, IClock &) override;
        void restart() override;
};