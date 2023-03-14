/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** core
*/

#ifndef CORE_H_
    #define CORE_H_
    #include "various.hpp"

namespace Core
{
    class Core {
        public:
            Core();
            ~Core();
    };
}

/**
 * @brief Core entry point
 *
 * @param baseGraphicalsLibsName
 * @return int
 */
int coreEntryPoint(const std::string &baseGraphicalsLibsName);

#endif /* !CORE_H_ */
