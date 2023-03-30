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

        IWindow::EventHandler &getEventBinding() override
        {
            throw std::runtime_error("method not implemented: getEventBinding");
        };

        bool processGameTick(IGrid &, IText &, IText &, IClock &) override
        {
            throw std::runtime_error("method not implemented: stop");
            return true;
        };

        void restart()
        {
            throw std::runtime_error("method not implemented: restart");
        }
};
