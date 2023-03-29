/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGame
*/

#pragma once
#include "../../Interface/Graphical/IGraphicalFactory.hpp"
#include "../../Interface/Game/IGame.hpp"
#include <stdexcept>

class AGame : public IGame
{
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
