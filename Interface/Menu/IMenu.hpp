/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IMenu
*/

#pragma once
#include "../Graphical/IGraphicalFactory.hpp"

/**
 * @brief
 *
 */
class IMenu
{

    public:
        using LambdaCoreLoading = std::function<void(std::string, std::string)>;

        ~IMenu() = default;

        /**
         * @brief Retrieves the event binding object for the window.
         * This function returns a reference to an object of type IWindow::EventHandler,
         * which is used to handle events for the window.
         * @return IWindow::EventHandler& A reference to an object of type IWindow::EventHandler.
         */
        virtual IWindow::EventHandler &getEventBinding() = 0;

        /**
         * @brief Loads the core actions required for the implementation.
         *
         * This function is used to load the core actions required for the implementation
         * using a LambdaCoreLoading parameter.
         *
         * @param LambdaCoreLoading A parameter of type LambdaCoreLoading that is used to load
         * the core actions.
         */
        virtual void loadCoreActions(LambdaCoreLoading) = 0;

        /**
         * @brief Processes a tick in the game menu.

         * This function is used to process a tick in the game menu, using several
         * parameters of type IText and an array of references to IText objects. It returns
         * a boolean value indicating whether or not the menu should continue to be processed.
         *
         * @param IText A parameter of type IText that is used to process the game menu.
         * @param IText A parameter of type IText that is used to process the game menu.
         * @param std::array<std::reference_wrapper<IText>, 3> An array of references to IText
         * objects.
         * @param std::array<std::reference_wrapper<IText>, 3> An array of references to IText
         * objects.
         * @return true The menu should continue to be processed.
         * @return false The menu should not continue to be processed.
         */
        virtual bool processMenuTick(IText &, IText &, std::array<std::reference_wrapper<IText>, 3>,
                                     std::array<std::reference_wrapper<IText>, 3>) = 0;

        /**
         * @brief Restarts the game.
         *
         * This function is used to restart the game. It is declared as a pure virtual function,
         * so it must be implemented by any derived classes.
         */
        virtual void restart() = 0;
};
