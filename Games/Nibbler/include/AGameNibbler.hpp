/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include <ctime>
#define INITIAL_LENGTH 4;
#define MAP_PATH "./assets/map.txt"
#define SPAWN_X 31
#define SPAWN_Y 37

class AGameNibbler : public AGame
{
    private:
        int width;
        int height;
        const char empty = ' ';
        const char wall = 'W';
        const char snake = '#';
        const char food = '+';
        const int initialLength = INITIAL_LENGTH;
        bool gameOver;
        int dx; // horizontal movement direction
        int dy; // vertical movement direction
        int _score;
        int foodX ;
        int foodY ;
        double speepFactor;
        std::clock_t _clock;

        std::vector<std::vector<char>> _map;
        std::vector<std::vector<char>> _board;
        std::vector<std::pair<int, int>> _snakeCoords;
        std::vector<std::pair<int, int>> _unavailableFoodCoo;

        void openMap();
        void clearBoard();
        void drawnSnake();
        void drawnFood();
        void displayBoard(IGrid &);
        void snakeStuck();
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