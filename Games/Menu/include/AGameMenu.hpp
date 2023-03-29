/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameMenuMenu
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameMenu : public AGame<GameEngine> {
private:

public:
    AGameMenu(): AGame<GameEngine>() {};
    AGameMenu(IGraphicalFactory &, IWindow::EventHandler &) {};
    ~AGameMenu() {};
};
