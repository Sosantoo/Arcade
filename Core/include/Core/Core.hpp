/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#pragma once
#include "lib/LibFileManager.hpp"
#include "Core/GameLib.hpp"
#include "Core/GraphicalLib.hpp"
#include "Core/MenuLib.hpp"

namespace Core
{
    class Core {
    private:
        enum GameState {
            GAME_LOOP,
            MENU_LOOP,
        };

        LibFileManager _LibFileManager;
        IWindow::EventHandler coreEventBindings;
        GraphicalLib _graphical;
        GameLib _game;
        MenuLib _menu;
        GameState gameState;

        //actions
        void nextGraphicsLibrary();
        void nextGameLibrary();
        void restartGame();
        void goToMenu();
        void closeGraphical();

        //loadings
        void bindEvents();


    public:
        Core(const std::string &);
        ~Core();

        void init(const std::string, const std::string);
        void launch();
        void loopMenu();
        void loopGame();
    };
};

// entrypoint core
int coreEntryPoint(const std::string &graphicalPathLib);