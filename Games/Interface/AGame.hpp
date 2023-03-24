/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#pragma once
#include "../../Interface/Game/IGames.hpp"
#include "../../Interface/Graphical/IGraphicals.hpp"

template<typename GameEngine>
class AGame: public IGame {
private:
    IGraphical *_graphical;
    IEvent::EventHandler _coreEvent;
    GameEngine gameEngine;

public:
    AGame() {};
    AGame(const AGame&) = delete;
    AGame& operator=(const AGame&) = delete;
    AGame(AGame&&) = delete;
    AGame& operator=(AGame&&) = delete;
    ~AGame() {};

    virtual void start(IGraphical &, IEvent::EventHandler &) override { throw std::runtime_error("method not implemented"); };

    virtual void stop() override { throw std::runtime_error("method not implemented"); };

    virtual void restart() override { throw std::runtime_error("method not implemented"); };
};
