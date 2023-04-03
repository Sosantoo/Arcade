/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IWindow
*/

#pragma once
#include "IEntity.hpp"
#include <functional>
#include <map>
#include <memory>

class IWindow
{
    public:
        ~IWindow() = default;

        /**
         * @brief
         *
         * @param name
         * @param width
         * @param height
         */
        virtual void initWindow(std::string name, size_t width, size_t height) = 0;

        /**
         * @brief
         *
         */
        virtual void closeWindow() = 0;

        /**
         * @brief
         *
         * @return true
         * @return false
         */
        virtual bool windowIsOpen() = 0;

        /**
         * @brief
         *
         */
        virtual void clear() = 0;

        /**
         * @brief
         *
         */
        virtual void display() = 0;

        /**
         * @brief
         *
         */
        enum class EventType {
            UP_pressed,
            DOWN_pressed,
            LEFT_pressed,
            RIGHT_pressed,
            QUIT,
            PAUSE,
            RESUME,
            NEXT_GAME,
            NEXT_LIB,
            RESTART,
            GO_TO_MENU,
        };

        using EventCallBack = std::function<void()>;
        using EventHandler = std::map<IWindow::EventType, EventCallBack>;

        /**
         * @brief
         *
         */
        virtual void callEvent(const IWindow::EventType) = 0;

        /**
         * @brief
         *
         */
        virtual void loadEventBindings(EventHandler &) = 0;

        /**
         * @brief
         *
         */
        virtual void eventPollEvent() = 0;

        /**
         * @brief
         *
         * @return std::unique_ptr<IText>
         */
        virtual std::unique_ptr<IText> createIText() = 0;

        /**
         * @brief
         *
         * @return std::unique_ptr<IGrid>
         */
        virtual std::unique_ptr<IGrid> createIGrid() = 0;
};
