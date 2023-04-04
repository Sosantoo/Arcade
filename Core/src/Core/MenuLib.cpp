/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** MenuLib
*/

#include "Core/MenuLib.hpp"
#include <iostream>

MenuLib::MenuLib()
{
}

MenuLib::~MenuLib()
{
}

void MenuLib::load(Lib::lib libDetails) {
    std::cout << "[CORE] Loading menu: " << libDetails.name << std::endl;;
    _libDetails = libDetails;
    _currentLib.load(libDetails, Lib::_MENU_);
}

IMenu& MenuLib::getInterface() {
    return _currentLib.getInterface();;
}
