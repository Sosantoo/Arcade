/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** GameLib
*/

#include "Core/GameLib.hpp"
#include <iostream>

GameLib::GameLib()
{
}

GameLib::~GameLib()
{
}

void GameLib::load(Lib::lib libDetails) {
    std::cout << "[CORE] Loading game: " << libDetails.name << std::endl;;
    _libDetails = libDetails;
    _currentLib.load(libDetails, Lib::_GAMES_);
}

IGame& GameLib::getInterface() {
    return _currentLib.getInterface();;
}
