/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** dlfcnExceptions
*/

#ifndef DLFCNEXCEPTIONS_HPP_
    #define DLFCNEXCEPTIONS_HPP_
    #include "Exceptions/BasicExceptions.hpp"

namespace DlfcnExceptions
{
    class CannotOpenExceptions: public BasicExceptionWithMessage {
        public:
            CannotOpenExceptions(const std::string&);
    };

    class CannotLoadExceptions: public BasicExceptionWithMessage {
        public:
            CannotLoadExceptions(const std::string&);
    };
}

#endif /* !DLFCNEXCEPTIONS_HPP_ */
