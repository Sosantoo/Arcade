/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#ifndef CORE_H_
    #define CORE_H_
    #include "../various.hpp"
    #include "../Wrapper/Wrapper.hpp"

namespace Core
{
    class Core {
        public:
            Core();
            ~Core();

        private:
    };
}

// entrypoint core
int coreEntryPoint(const std::string &baseGraphicalsLibsName = "arcade_sdl2.so");

#endif /* !CORE_H_ */
