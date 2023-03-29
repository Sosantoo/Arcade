/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#pragma once
#include "../Wrapper/Wrapper.hpp"
#include "../interface.hpp"

namespace Core
{

    class Core
    {
        private:
            InterfaceWrapper<IGraphical> _graphical;
            InterfaceWrapper<IGame> _game;
            IEvent::EventHandler event;
            Lib::lib_t _graphical_details;
            Lib::lib_t _game_details;
            libWrapper &_libs;

            // actions
            void nextGraphicsLibrary();
            void nextGameLibrary();
            void restartGame();
            void goToMenu();
            void closeGraphical();

            // loadings
            void loadStack();
            void loadGraphical();
            void loadGame();

        public:
            Core(libWrapper &);
            ~Core() = default;

            void init(std::string, std::string);

            void launchGame();

        protected:
            IEvent::EventHandler &getCoreEventBind();
    };
}; // namespace Core

// entrypoint core
int coreEntryPoint(const std::string &baseGraphicalsLibsName);
