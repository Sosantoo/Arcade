/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** MenuLib
*/

#pragma once
#include "lib/LibHandler.hpp"
#include "lib/LibFileManager.hpp"
#include "interface.hpp"

class MenuLib {
private:
    LibHandler<IMenu> _currentLib;

public:
    MenuLib();
    ~MenuLib();

    Lib::lib _libDetails;
    void load(Lib::lib);
    IMenu& getInterface();
};
