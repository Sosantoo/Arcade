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
    AGameTest(IGraphical &, IEvent::EventHandler &) {};
    ~AGameTest() {};

    virtual void start(IGraphical &, IEvent::EventHandler &) final;
    virtual void stop() final;
    virtual void restart() final;
};
