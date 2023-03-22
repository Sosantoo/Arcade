/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** nCurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_
    #include "../../../Core/include/various.hpp"
    #include "../../../Interface/Graphical/IGraphicals.hpp"
    #include <ncurses.h>

class AGraphical: public IGraphical {
    public:
    AGraphical()
        : _eventBinding{ nullptr} {};
    ~AGraphical() {};

    // IGraphical
    virtual void loadResource() {};
    virtual void resetResource() {};

    //IWindow
    virtual void openWindow() final {};
    virtual void closeWindow() final {};
    virtual void initWindow(std::string, std::pair<size_t, size_t>) final {};
    virtual bool windowIsOpen() final {};
    virtual void clear() final {};
    virtual void display() final {};

    //IEvent
    virtual void loadEventBindings(EventHandler &) final {};

    // IEntity
    virtual void create() final {};

    virtual void setSize() final {};

    virtual void setPosition() final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    private:
        EventHandler *_eventBinding;
        std::unordered_map<int, bool> keyState;
};

#endif /* !NCURSES_HPP_ */
