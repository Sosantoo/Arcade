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
#include <bits/stdc++.h>

// function to generate a random integer within a given range
int random(int min, int max) {
    return min + (rand() % (max - min + 1));
}

AGameSnake::AGameSnake()
    : width{50}
    , height{50}
    , gameOver{false}
    , _score{0}
    , foodX{0}
    , foodY{0}
    , speepFactor{5.0}
    , _clock{std::clock()}
    , _board(height, std::vector<char>(width, empty))
{
    srand(time(nullptr));
    for (int i = 0; i < initialLength; i++) {
        _snakeCoords.push_back(std::make_pair(width / 2 + i, height / 2));
    }
    generateFood();
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
                 {IWindow::EventType::RESTART,
                 [this]() {
                    this->restart();
                 }},
            });
}

void AGameSnake::generateFood() {
    foodX = random(1, width - 2);
    foodY = random(1, height - 2);
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

        if (x < 1 || x >= width - 1 || y < 1 || y >= height - 1) {
            // snake has gone out of bounds, game over
            gameOver = true;
        } else if (x == foodX && y == foodY) {
            _score++;
            speepFactor += 0.1 * speepFactor;
            _snakeCoords.push_back(_snakeCoords.back());
            generateFood();
            return;
        } else {
            _board[y][x] = snake;
        }
    }
}

void AGameSnake::drawnFood() {
    _board[foodY][foodX] = food;
}

void AGameSnake::displayBoard(IGrid &grid) {
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
    if (gameOver)
        return;
    int headX = _snakeCoords.back().first;
    int headY = _snakeCoords.back().second;
    headX += dx;
    headY += dy;

    if (_board[headY][headX] == snake)
        gameOver = true;
    _snakeCoords.erase(_snakeCoords.begin());// remove the tail segment
    _snakeCoords.push_back(std::make_pair(headX, headY)); // add the new head segment
}

void AGameSnake::displayGraphicalInfo(IText& scoreText, IText& timeText) {
    scoreText.changeString("Score: " + std::to_string(_score));
    scoreText.displayEntity();

    int duration = std::floor((std::clock() - _clock) / static_cast<int>(CLOCKS_PER_SEC));
    timeText.changeString("Time: " + std::to_string(duration));
    timeText.displayEntity();
}


bool AGameSnake::processGameTick(IGrid &grid, IText &scoreText, IText &timeText, IClock &clock) {
    clearBoard();
    drawnSnake();
    drawnFood();
    displayBoard(grid);
    displayGraphicalInfo(scoreText, timeText);

    if (clock.getTimeElapsed() <= 50 )
        return false;
    clock.resetClock();
    moveAllSnake();

    if (gameOver)
        restart();
    return false;
};

void AGameSnake::restart()
{
    gameOver = false;
    dx = 1;
    dy = 0;
    _score = 0;
    speepFactor = 0;
    _snakeCoords.clear();
    for (int i = 0; i < initialLength; i++) {
        _snakeCoords.push_back(std::make_pair(width / 2 + i, height / 2));
    }
    generateFood();
}