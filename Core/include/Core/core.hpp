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
            Core();
            ~Core();

            void testGraphicals();
            void testGame();
            void start(const std::string GraphicalsLibPath, const std::string GameLibPath);

        private:
            InterfaceWrapper<IGraphical> _graphical;
            InterfaceWrapper<IGame> _game;
    };
}

// entrypoint core
int coreEntryPoint(const std::string &baseGraphicalsLibsName = "arcade_sdl2.so");

#endif /* !CORE_H_ */
