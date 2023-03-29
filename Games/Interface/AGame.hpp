/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#pragma once
#include "../../Interface/Game/IGames.hpp"
#include "../../Interface/Graphical/IGraphicals.hpp"
#include <stdexcept>

template <typename GameEngine> class AGame : public IGame
{
    protected:
        IGraphical *_graphical;
        GameEngine gameEngine;

    public:
        AGame() = default;
        AGame(const AGame &) = delete;
        AGame &operator=(const AGame &) = delete;
        AGame(AGame &&) = delete;
        AGame &operator=(AGame &&) = delete;
        ~AGame() = default;

        IEvent::EventHandler &getEventBinding() override
        {
            throw std::runtime_error("method not implemented: stop");
        };

        void processGameTick(IClock &clock) override
        {
            (void)clock;
            throw std::runtime_error("method not implemented: stop");
        };

        std::vector<IEntity> getEntity() override
        {
            throw std::runtime_error("method not implemented: stop");
        };
};
