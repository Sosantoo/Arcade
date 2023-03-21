/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#ifndef CORE_H_
    #define CORE_H_
    #include "../various.hpp"
    #include "../interface.hpp"
    #include "../Wrapper/Wrapper.hpp"

namespace Core
{

    class Core {
        public:
            Core(libWrapper &);
            ~Core();

            void start(const std::string, const std::string);
            void test();

            //actions
            void nextGraphicsLibrary();
            void nextGame();
            void restartGame();
            void goToMenu();
            void exit();

        protected:
            InterfaceWrapper<IGraphical> _graphical;
            InterfaceWrapper<IGame> _game;
            Lib::lib_t _graphical_details;
            Lib::lib_t _game_details;
            libWrapper &_libs;

    };
};

// entrypoint core
int coreEntryPoint(const std::string &baseGraphicalsLibsName = "arcade_sdl2.so");

#endif /* !CORE_H_ */
