/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGame
*/

#pragma once
#include "../Graphical/IGraphicalFactory.hpp"

class IGame {
    public:
        ~IGame() = default;

        /**
         * @brief Get the Event Binding object
         *
         * @return IWindow::EventHandler&
         */
        virtual IWindow::EventHandler &getEventBinding() = 0;

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        virtual bool processGameTick(IGrid &, IText &, IText &, IClock &) = 0;

        /**
         * @brief
         *
         */
        virtual void restart() = 0;
};
