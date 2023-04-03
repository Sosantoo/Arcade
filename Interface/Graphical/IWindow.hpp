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
         * @brief Initializes the window object required for the implementation.
         * Its purpose is to initialize the window object with the specified name, width, and
         * height.
         * @param name
         * @param width
         * @param height
         */
        virtual void initWindow(std::string name, size_t width, size_t height) = 0;

        /**
         * @brief loses the window object used in the implementation.
         *Its purpose is to close and destroy the window object used in the implementation.
         */
        virtual void closeWindow() = 0;

        /**
         * @brief Checks whether the window object used in the implementation is currently open.
         * Its purpose is to check whether the window object used in the implementation is currently
         * open.
         * @return true
         * @return false
         */
        virtual bool windowIsOpen() = 0;

        /**
         * @brief Clears the rendering buffer used in the implementation.
         * Its purpose is to clear the rendering buffer used in the implementation.
         * This is typically done at the beginning of each frame to ensure that the previous frame's
         * rendering is not visible in the current frame.
         */
        virtual void clear() = 0;

        /**
         * @brief Displays the rendered content on the window object used in the implementation.
         * Its purpose is to display the rendered content on the window object used in the
         * implementation. This is typically done at the end of each frame to show the newly
         * rendered content on the screen.
         */
        virtual void display() = 0;

        /**
         * @brief Calls the event handler function for the specified event type.
         * Its purpose is to call the event handler function for the specified event type.
         * This function is typically called by the application's main loop to handle user input or
         * other events.
         * @param eventType An object of type IWindow::EventType specifying the type of the event to
         * be handled.
         */
        virtual void callEvent(const IWindow::EventType) = 0;

        /**
         * @brief oads the event bindings for the specified event handler object.
         * Its purpose is to load the event bindings for the specified event handler object.
         * This function is typically called at the beginning of the application to register event
         * handlers for various types of events (e.g. mouse clicks, key presses, etc.).
         * @param handler An object of type EventHandler that contains the event bindings to be
         * loaded.
         */
        virtual void loadEventBindings(EventHandler &) = 0;

        /**
         * @brief  Polls for any pending events on the window object used in the implementation.
         * Its purpose is to poll for any pending events on the window object used in the
         * implementation. This function is typically called by the application's main loop to
         * handle user input or other events.
         */
        virtual void eventPollEvent() = 0;

        /**
         * @brief Creates a new instance of the IText interface for the implementation.
         * Its purpose is to create a new instance of the IText interface for the implementation.
         * The returned object can be used to draw text on the window.
         * @return std::unique_ptr<IText>
         */
        virtual std::unique_ptr<IText> createIText() = 0;

        /**
         * @brief Creates a new instance of the IGrid interface for the implementation.
         * Its purpose is to create a new instance of the IGrid interface for the implementation.
         * The returned object can be used to draw a grid on the window.
         * @return std::unique_ptr<IGrid>
         */
        virtual std::unique_ptr<IGrid> createIGrid() = 0;

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
};
