/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicalFactorys
*/

#pragma once
#include "IClock.hpp"
#include "IEntity.hpp"
#include "IWindow.hpp"
#include <memory>

class IGraphicalFactory
{
    public:
        ~IGraphicalFactory() = default;

        /**
         * @brief Loads the necessary resources required for the implementation of the program.
         * Its purpose is to load any required resources that are used in the implementation, such
         * as textures, sounds, or fonts, into memory so they can be used later on.
         */
        virtual void loadResource() = 0;

        /**
         * @brief Releases the resources held by the implementation.
         * Its purpose is to release any resources that have been allocated or loaded by the
         * implementation, such as textures, sounds, or fonts that were loaded during the
         * course of the program.
         * It ensure that all resources are properly released to avoid any memory leaks or resource
         * conflicts.
         */
        virtual void destroyRessource() = 0;

        /**
        @brief This function creates a window object required for the implementation.
        @param name A string specifying the name of the window to be created.
        @param width A size_t specifying the width of the window to be created.
        @param height A size_t specifying the height of the window to be created.
        @return std::unique_ptr<IWindow> A unique_ptr<IWindow> object pointing to the newly created
        window.
        */
        virtual std::unique_ptr<IWindow> createWindow(std::string name, size_t width,
                                                      size_t height) = 0;

        /**
         * @brief Creates an IClock object required for the implementation.
         * Its purpose is to create a new IClock object, which is used to track time in the
         * implementation.
         * @param width
         * @param height
         * @return std::unique_ptr<IClock> A unique_ptr<IClock> object pointing to the newly created
         * IClock.
         */
        virtual std::unique_ptr<IClock> createIClock() = 0;
};
