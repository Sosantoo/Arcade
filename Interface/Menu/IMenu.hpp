/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IMenu
*/

#pragma once
#include "../Graphical/IGraphicalFactory.hpp"

class IMenu {

    public:
        using LambdaLoadingGraphicsByName =  std::function<void(std::string libName)>;
        using LambdaLoadingGameByName =  std::function<void(std::string libName)>;

        ~IMenu() = default;

        virtual IWindow::EventHandler &getEventBinding() = 0;

        virtual void loadCoreActions(LambdaLoadingGraphicsByName, LambdaLoadingGameByName) = 0;

        virtual bool processMenuTick(IText &, IText &, std::array<std::reference_wrapper<IText>, 3>, std::array<std::reference_wrapper<IText>, 3>) = 0;

        virtual void restart() = 0;
};
