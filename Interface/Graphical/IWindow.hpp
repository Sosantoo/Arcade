/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IWindow
*/

#pragma once
#include "../../Core/include/various.hpp"

class IWindow {
public:
    ~IWindow() = default;

    virtual void openWindow() = 0;

    virtual void closeWindow() = 0;

    virtual void initWindow(std::string, std::pair<size_t, size_t>) = 0;

    virtual bool windowIsOpen() = 0;

    virtual void clear() = 0;

    virtual void display() = 0;

};
