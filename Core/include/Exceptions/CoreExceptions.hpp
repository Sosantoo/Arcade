/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreExceptions
*/

#ifndef COREEXCEPTIONS_HPP_
    #define COREEXCEPTIONS_HPP_
    #include "BasicExceptions.hpp"

namespace CoreExceptions
{
    class RuntimeExceptions: public BasicExceptionWithMessage {
        public:
            RuntimeExceptions(const std::string&);
    };

    class LibUnknowExceptions: public BasicExceptionWithMessage {
        public:
            LibUnknowExceptions(const std::string&);
    };
}

#endif /* !COREEXCEPTIONS_HPP_ */
