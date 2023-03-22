/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** EventHandler
*/

#ifndef EVENTHANDLER_HPP_
    #define EVENTHANDLER_HPP_
    #include "various.hpp"

class EventHandler {
public:
    EventHandler(IGraphical &graphical);
    ~EventHandler();

    void upKeyPress();

    void downKeyPress();

    void leftKeyPress();

    void rightKeyPress();

    IEvent::EventHandler &getEventBindings();

protected:
    IEvent::EventHandler eventHandler;
private:
    IGraphical &_graphical;
};

#endif /* !EVENTHANDLER_HPP_ */
