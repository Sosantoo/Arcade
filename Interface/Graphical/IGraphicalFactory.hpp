/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicalFactorys
*/

#pragma once
#include <memory>
#include "IClock.hpp"
#include "IEntity.hpp"
#include "IWindow.hpp"

class IGraphicalFactory {
public:
    ~IGraphicalFactory() = default;

    virtual void loadResource() = 0;

    virtual void destroyRessource() = 0;

    //factory
    virtual std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) = 0;

    virtual std::unique_ptr<IClock> createIClock() = 0;
};
