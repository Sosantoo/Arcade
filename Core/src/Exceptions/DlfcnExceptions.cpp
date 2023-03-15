/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** WrapperExceptions
*/

#include "arcade.hpp"

DlfcnExceptions::CannotOpenExceptions::CannotOpenExceptions(const std::string& errorMsgDetails)
    : BasicExceptionWithMessage("[dlfcn]", "Cannot Open: " + errorMsgDetails)
{
}

DlfcnExceptions::CannotLoadExceptions::CannotLoadExceptions(const std::string& errorMsgDetails)
    : BasicExceptionWithMessage("[dlfcn]", "Cannot load exceptions" + errorMsgDetails)
{
}
