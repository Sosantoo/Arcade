/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-arcade-leopold.sallan-gemard
** File description:
** IGraphicals
*/

#ifndef IGRAPHICAL_HPP_
    #define IGRAPHICAL_HPP_
    #include "../Core/include/various.hpp"

class IWindow {
public:
    ~IWindow() = default;

    virtual void display() const = 0;

    virtual void initWindow(std::string, std::pair<size_t, size_t>) const = 0;

    virtual void openWindow() const = 0;

    virtual void closeWindow() const = 0;

};

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
    };

    ~IEvent() = default;

    using EventCallBack = std::function<void()>;
    using EventHandler = std::map<EventType, EventCallBack>;

    virtual void loadEventBindings(IEvent::EventHandler &) = 0;
};

class IGrid {
public:
    enum class Color {
        Blue,
        Green,
        Orange,
        Red,
        Brown,
        Yellow,
    };

    struct {
        Color color;
        size_t x;
        size_t y;
    } Cell;

    ~IGrid() = default;

    virtual void createGrid() const = 0;

    virtual void updateCell() const = 0;
};

class IGraphical:
    public IWindow,
    public IEvent,
    public IGrid
{
public:
    ~IGraphical() = default;

    virtual void display() const = 0;

    virtual void createSprite() const = 0;
};

#endif