/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicals
*/

#pragma once
#include "IClock.hpp"
#include "IEvent.hpp"
#include "IEntity.hpp"
#include "IWindow.hpp"

class IGraphical:
    public IWindow,
    public IEvent,
    public IEntity
{
public:
    ~IGraphical() = default;

    virtual void loadResource() = 0;

    virtual void resetResource() = 0;
};
