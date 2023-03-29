/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** CoreExceptions
*/

#include "Exceptions/CoreExceptions.hpp"

CoreExceptions::RuntimeExceptions::RuntimeExceptions(const std::string& errorMsgDetails)
    : BasicExceptionWithMessage("[Core]", "Cannot Open: " + errorMsgDetails)
{
}

CoreExceptions::LibUnknowExceptions::LibUnknowExceptions(const std::string& errorMsgDetails)
    : BasicExceptionWithMessage("[Core]", "Unknow lib:" + errorMsgDetails)
{
}