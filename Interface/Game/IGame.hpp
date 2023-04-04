/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGame
*/

#pragma once
#include "../Graphical/IGraphicalFactory.hpp"

class IGame
{
    public:
        ~IGame() = default;

        /**
         * @brief Returns the event handler object for the window.
         * Its purpose is to return the event handler object for the window, allowing the client to
         * modify or access event bindings.
         * The function returns a reference to the IWindow::EventHandler object associated with the
         * window.
         * @return IWindow::EventHandler&
         */
        virtual IWindow::EventHandler &getEventBinding() = 0;

        /**
         * @brief Process a single tick of the game or simulation.
         * Its purpose is to process a single tick of the game or simulation, updating the state of
         * the game or simulation accordingly. The function takes four parameters: a reference to an
         * IGrid object representing the game board or simulation space, a reference to an IText
         * object representing the score or other information to be displayed, a reference to an
         * IClock object representing the game or simulation timer, and a reference to an IText
         * object representing the time or other information to be displayed. The function returns a
         * boolean value indicating whether the game or simulation should continue running. If
         * false, the game or simulation should end and any necessary cleanup should be performed.
         * @param grid
         * @param scoreText
         * @param timeText
         * @param clock
         * @return true
         * @return false
         */
        virtual bool processGameTick(IGrid &grid, IText &scoreText, IText &timeText,
                                     IClock &clock) = 0;

        /**
         * @brief Restarts the implementation's game or simulation.
         * Its purpose is to restart the game or simulation implemented by the class, resetting all
         * necessary variables and objects to their initial state.
         */
        virtual void restart() = 0;
};
