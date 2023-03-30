/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreExceptions
*/

#pragma once
#include "BasicExceptions.hpp"

namespace CoreExceptions
{
    class RuntimeExceptions : public BasicExceptionWithMessage
    {
        public:
            RuntimeExceptions(const std::string &);
    };

    class LibUnknowExceptions : public BasicExceptionWithMessage
    {
        public:
            LibUnknowExceptions(const std::string &);
    };
} // namespace CoreExceptions
