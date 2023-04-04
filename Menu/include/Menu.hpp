/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "LibFileManager.hpp"
#include "../../Interface/Menu/IMenu.hpp"
#include "../../Interface/Graphical/IGraphicalFactory.hpp"

class Menu: public IMenu
{
    private:
        // file management:
        LibFileManager _libFileManager;
        std::vector<Lib::lib> _gameLibs;
        std::vector<Lib::lib> _graphicLibs;
        size_t _gameLibsSelected;
        size_t _graphicsLibsSelected;

        // render
        std::string getLibGameName(size_t);
        std::string getLibGraphicsName(size_t);
        void displayTexts(IText &, IText &, std::array<std::reference_wrapper<IText>, 3>, std::array<std::reference_wrapper<IText>, 3>);

        //event
        LambdaLoadingGraphicsByName _loadGraphics;
        LambdaLoadingGameByName _LoadGame;
        IWindow::EventHandler _gameEvent;
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