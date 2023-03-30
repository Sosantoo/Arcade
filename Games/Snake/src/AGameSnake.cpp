/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "AGameSnake.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// function to generate a random integer within a given range
int random(int min, int max) {
    return min + (rand() % (max - min + 1));
}

AGameSnake::AGameSnake()
    : _board(height, std::vector<char>(width, empty))
{
    srand(time(nullptr));
    for (int i = 0; i < initialLength; i++) {
        _snakeCoords.push_back(std::make_pair(width / 2 + i, height / 2));
    }
    generateFood();
    width = 50;
    height = 50;
    gameOver = false;
    dx = 1;
    dy = 0;
    score = 0;
    foodX = 0;
    foodY = 0;
}

void AGameSnake::upKeyPress()
{
    std::cout << "[Game Engine] upKeyPress process" << std::endl;
    if (dy == -1)
        return;
    dy = dy != 0 ? dy : -1;
    dx = 0;
};

void AGameSnake::downKeyPress()
{
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
    dy = dy != 0 ? dy : 1;
    dx = 0;
};

void AGameSnake::leftKeyPress()
{
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
    dx = dx != 0 ? dx : -1;
    dy = 0;
};

void AGameSnake::rightKeyPress()
{
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
    dx = dx != 0 ? dx : 1;
    dy = 0;
};

IWindow::EventHandler &AGameSnake::getEventBinding()
{
    return (gameEvent = {
                {IWindow::EventType::UP_pressed,
                 [this]() {
                     this->upKeyPress();
                 }},
                {IWindow::EventType::DOWN_pressed,
                 [this]() {
                     this->downKeyPress();
                 }},
                {IWindow::EventType::LEFT_pressed,
                 [this]() {
                     this->leftKeyPress();
                 }},
                {IWindow::EventType::RIGHT_pressed,
                 [this]() {
                     this->rightKeyPress();
                 }},
            });
}

void AGameSnake::generateFood() {
    foodX = random(1, width - 1);
    foodY = random(1, height - 1);
}

void AGameSnake::clearBoard() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 || x == 0 || y == width - 1 || x == width - 1)
                _board[y][x] = wall;
            else
                _board[y][x] = empty;
        }
    }
}

void AGameSnake::drawnSnake() {
    for (auto& coord : _snakeCoords) {
        auto [x, y] = coord;

        if (x - 1 < 0 || x >= width - 1 || y - 1 < 0 || y >= height - 1) {
            // snake has gone out of bounds, game over
            gameOver = true;
        // } else if (_board[y][x] == snake) {
        //     // snake has collided with itself, game over
        //     std::cout << " snake collided with itself" << std::endl;
        //     gameOver = true;
        } else if (x == foodX && y == foodY) {
            // snake has eaten the food
            score++;
            _snakeCoords.push_back(_snakeCoords.back());
            foodX = random(0, width - 1);
            foodY = random(0, height - 1);
            generateFood();
        } else {
            _board[y][x] = snake;
        }
    }
}

void AGameSnake::drawnFood() {
    _board[foodY][foodX] = food;
}

void AGameSnake::displayBoard(IGrid &grid) {
    IEntity::Color color;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (_board[y][x] == empty)
                grid.updateCell(x, y, IEntity::Color::Yellow);
            if (_board[y][x] == snake)
                grid.updateCell(x, y, IEntity::Color::Orange);
            if (_board[y][x] == food)
                grid.updateCell(x, y, IEntity::Color::Brown);
            if (_board[y][x] == wall)
                grid.updateCell(x, y, IEntity::Color::Red);
        }
    }
}

void AGameSnake::moveAllSnake() {
    int headX = _snakeCoords.back().first;
    int headY = _snakeCoords.back().second;
    headX += dx;
    headY += dy;
    _snakeCoords.erase(_snakeCoords.begin());// remove the tail segment
    _snakeCoords.push_back(std::make_pair(headX, headY)); // add the new head segment
}

bool AGameSnake::processGameTick(IGrid &grid, IText &score, IText &time, IClock &clock) {
    clearBoard();
    drawnSnake();
    drawnFood();
    displayBoard(grid);
    moveAllSnake();

    if (gameOver)
        restart();
    return gameOver;
};

void AGameSnake::restart()
{
    std::cout << "[SNAKE] GAME OVER" << std::endl;
    width = 50;
    height = 50;
    gameOver = false;
    dx = 1;
    dy = 0;
    score = 0;
    foodX = 0;
    foodY = 0;
}