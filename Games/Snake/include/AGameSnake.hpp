/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameSnake : public AGame<GameEngine> {
private:

public:
    AGameSnake(): AGame<GameEngine>() {};
    AGameSnake(IGraphicalFactory &, IWindow::EventHandler &) {};
    ~AGameSnake() {};
};