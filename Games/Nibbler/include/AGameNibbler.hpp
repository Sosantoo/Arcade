/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include <curses.h>
#include <ctime>
#define INITIAL_LENGTH 3;

class AGameNibbler : public AGame
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
        int dx; // horizontal movement direction
        int dy; // vertical movement direction
        int _score;
        int foodX ;
        int foodY ;
        double speepFactor;
        std::clock_t _clock;

        std::vector<std::vector<char>> _board;
        std::vector<std::pair<int, int>> _snakeCoords;

        void generateFood();
        void clearBoard();
        void drawnSnake();
        void drawnFood();
        void displayBoard(IGrid &);
        void moveAllSnake();
        void displayGraphicalInfo(IText &, IText &);

        IWindow::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();

    public:
        AGameNibbler();
        ~AGameNibbler() = default;
        IWindow::EventHandler &getEventBinding() override;
        bool processGameTick(IGrid &, IText &, IText &, IClock &) override;
        void restart() override;
};