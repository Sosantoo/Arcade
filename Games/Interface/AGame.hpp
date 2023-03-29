/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#pragma once
#include "../../Interface/Game/IGame.hpp"
#include "../../Interface/Graphical/IGraphicalFactory.hpp"

template<typename GameEngine>
class AGame: public IGame {
protected:
    IGraphicalFactory *_graphical;
    GameEngine gameEngine;

public:
    AGame() {};
    AGame(const AGame&) = delete;
    AGame& operator=(const AGame&) = delete;
    AGame(AGame&&) = delete;
    AGame& operator=(AGame&&) = delete;
    ~AGame() {};

    virtual IWindow::EventHandler &getEventBinding() override { throw std::runtime_error("method not implemented: stop"); };

    virtual void processGameTick(IClock &clock) override { (void)clock; throw std::runtime_error("method not implemented: stop"); };

    virtual std::vector<IEntity> getEntity() override { throw std::runtime_error("method not implemented: stop"); };

};
