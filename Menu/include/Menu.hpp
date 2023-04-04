/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/Menu/IMenu.hpp"
#include "../../Interface/Graphical/IGraphicalFactory.hpp"

class Menu: public IMenu
{
    private:
        IWindow::EventHandler gameEvent;

        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();

    public:
        Menu();
        ~Menu() = default;
        IWindow::EventHandler &getEventBinding() final;
        void loadCoreActions(LambdaLoadingGraphicsByName, LambdaLoadingGameByName) final;
        bool processMenuTick(IText &, IText &, std::array<std::reference_wrapper<IText>, 3>, std::array<std::reference_wrapper<IText>, 3>) final;
        void restart() final;
};