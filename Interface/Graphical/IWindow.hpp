/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IWindow
*/

#pragma once

class IWindow {
public:
    ~IWindow() = default;

    virtual void initWindow(std::string name, size_t width, size_t height) = 0;

    virtual void closeWindow() = 0;

    virtual bool windowIsOpen() = 0;

    virtual void clear() = 0;

    virtual void display() = 0;

    //event
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

    virtual void callEvent(const IWindow::EventType) = 0;

    virtual void loadEventBindings(EventHandler &) = 0;

    virtual void eventPollEvent() = 0;

};
