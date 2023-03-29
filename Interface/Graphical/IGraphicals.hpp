/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicals
*/

#pragma once
#include "IClock.hpp"
#include "IEntity.hpp"
#include "IEvent.hpp"
#include "IWindow.hpp"

class IGraphical : public IWindow, public IEvent, public IClock
{
    public:
        ~IGraphical() = default;

        virtual void loadResource() = 0;
        virtual void destroyRessource() = 0;
        virtual void displayEntity(std::vector<IEntity>) = 0;
};
