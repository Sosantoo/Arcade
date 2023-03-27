/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IEvent
*/

#pragma once
#include "../../Core/include/various.hpp"

class IEvent {
public:

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

    ~IEvent() = default;

    using EventCallBack = std::function<void()>;
    using EventHandler = std::map<IEvent::EventType, EventCallBack>;

    virtual void loadEventBindings(EventHandler &) = 0;
};
