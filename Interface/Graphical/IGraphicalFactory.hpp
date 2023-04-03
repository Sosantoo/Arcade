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

    /**
     * @brief
     *
     */
    virtual void loadResource() = 0;

    /**
     * @brief
     *
     */
    virtual void destroyRessource() = 0;

    /**
     * @brief Create a Window object
     *
     * @param name
     * @param width
     * @param height
     * @return std::unique_ptr<IWindow>
     */
    virtual std::unique_ptr<IWindow> createWindow(std::string name, size_t width, size_t height) = 0;

    /**
     * @brief Create a Grid object
     *
     * @param width
     * @param height
     * @return std::unique_ptr<IGrid>
     */
    virtual std::unique_ptr<IClock> createIClock() = 0;
};
