/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameTest : public AGame<GameEngine> {
private:

public:
    AGameTest(): AGame<GameEngine>() {};
    ~AGameTest() {};

    virtual IWindow::EventHandler &getEventBinding() final;

    virtual void processGameTick(IClock &clock) final;

    virtual std::vector<IEntity> getEntity() final;
};
