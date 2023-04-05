/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Game
*/

#include "AGameNibbler.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>

int random(int min, int max) {
    return min + (rand() % (max - min + 1));
}

AGameNibbler::AGameNibbler()
    : width{0}
    , height{0}
    , gameOver{false}
    , dx{1}
    , dy{0}
    , _score{0}
    , foodX{0}
    , foodY{0}
    , speepFactor{5.0}
    , _clock{std::clock()}
    , _board(height, std::vector<char>(width, empty))
{
    openMap();
    srand(time(nullptr));
    for (int i = 0; i < initialLength; i++) {
        _snakeCoords.push_back(std::make_pair(SPAWN_X + i, SPAWN_Y));
    }
}

void AGameNibbler::openMap()
{
    std::ifstream infile(MAP_PATH);
    if (!infile)
        throw std::runtime_error("Error opening file!");

    // Read the file line by line and store each character in a 2D vector
    std::string line;
    while (std::getline(infile, line)) {
        std::vector<char> row;
        for (auto& c : line) {
            row.push_back(c);
        }
        _map.push_back(row);
    }
    width = _map.size();
    height = _map[0].size();
    infile.close();
}

void AGameNibbler::upKeyPress()
{
    std::cout << "[Game Engine] upKeyPress process" << std::endl;
    if (dy == -1)
        return;
    dy = dy != 0 ? dy : -1;
    dx = 0;
};

void AGameNibbler::downKeyPress()
{
    std::cout << "[Game Engine] downKeyPress process" << std::endl;
    dy = dy != 0 ? dy : 1;
    dx = 0;
};

void AGameNibbler::leftKeyPress()
{
    std::cout << "[Game Engine] leftKeyPress process" << std::endl;
    dx = dx != 0 ? dx : -1;
    dy = 0;
};

void AGameNibbler::rightKeyPress()
{
    std::cout << "[Game Engine] rightKeyPress process" << std::endl;
    dx = dx != 0 ? dx : 1;
    dy = 0;
};

IWindow::EventHandler &AGameNibbler::getEventBinding()
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

void AGameNibbler::clearBoard() {
    _board = _map;
}

void AGameNibbler::drawnSnake() {
    for (auto& coord : _snakeCoords) {
        auto [x, y] = coord;

        if (x < 1 || x >= width - 1 || y < 1 || y >= height - 1) {
            // snake has gone out of bounds, game over
            gameOver = true;
        } else if (_board[y][x] == food) {
            _score++;
            speepFactor += 0.1 * speepFactor;
            _snakeCoords.push_back(_snakeCoords.back());
            _unavailableFoodCoo.push_back({x, y});
            return;
        } else {
            _board[y][x] = snake;
        }
    }
}

void AGameNibbler::drawnFood() {
    for (auto&e : _unavailableFoodCoo) {
        auto [x, y] = e;
        _board[y][x] = empty;
    }
}

void AGameNibbler::displayBoard(IGrid &grid) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (_board[y][x] == empty)
                grid.updateCell(x, y, IEntity::Color::Yellow);
            if (_board[y][x] == snake)
                grid.updateCell(x, y, IEntity::Color::Blue);
            if (_board[y][x] == food)
                grid.updateCell(x, y, IEntity::Color::Brown);
            if (_board[y][x] == wall)
                grid.updateCell(x, y, IEntity::Color::Red);
        }
    }
}

void AGameNibbler::snakeStuck() {
    std::cout << "snake stuck" << std::endl;
    int headX = _snakeCoords.back().first;
    int headY = _snakeCoords.back().second;

    //check if there is two options X:
    if (_board[headY][headX - 1] == empty && _board[headY][headX + 1] == empty)
        return;

    //check if there is two options Y:
    if (_board[headY - 1][headX] == empty && _board[headY + 1][headX] ==empty)
        return;

    // Check if there is a clear path to the left
    if (_board[headY][headX - 1] == empty) {
        dx = -1;
        dy = 0;
        return;
    }

    // Check if there is a clear path to the right
    if (_board[headY][headX + 1] == empty) {
        dx = 1;
        dy = 0;
        return;
    }

    // Check if there is a clear path upside
    if (_board[headY - 1][headX] == empty) {
        dx = 0;
        dy = -1;
        return;
    }

    // Check if there is a clear path downside
    if (_board[headY + 1][headX] == empty) {
        dx = 0;
        dy = 1;
        return;
    }
}

void AGameNibbler::moveAllSnake() {
    if (gameOver)
        return;
    int headX = _snakeCoords.back().first;
    int headY = _snakeCoords.back().second;
    headX += dx;
    headY += dy;

    if (_board[headY][headX] == snake)
        gameOver = true;
    if (_board[headY][headX] == wall) {
        snakeStuck();
       return;
    }
    _snakeCoords.erase(_snakeCoords.begin());// remove the tail segment
    _snakeCoords.push_back(std::make_pair(headX, headY)); // add the new head segment
}

void AGameNibbler::displayGraphicalInfo(IText &scoreText, IText &timeText) {
    scoreText.changeString("Score: " + std::to_string(_score));
    scoreText.displayEntity();

    double duration = ( std::clock() - _clock ) / (double) CLOCKS_PER_SEC;
    timeText.changeString("Time: " + std::to_string(std::floor(duration)));
    timeText.displayEntity();
}

bool AGameNibbler::processGameTick(IGrid &grid, IText &scoreText, IText &timeText, IClock &clock) {
    clearBoard();
    drawnFood();
    drawnSnake();
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

void AGameNibbler::restart()
{
    gameOver = false;
    dx = 1;
    dy = 0;
    _score = 0;
    speepFactor = 5.0;
    _snakeCoords.clear();
    _unavailableFoodCoo.clear();
    for (int i = 0; i < initialLength; i++) {
        _snakeCoords.push_back(std::make_pair(SPAWN_X + i, SPAWN_Y));
    }
}
