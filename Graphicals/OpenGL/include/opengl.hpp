/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** opengl
*/

#pragma once
    #include "../../../Core/include/various.hpp"
    #include "../../../Interface/Graphical/IGraphicals.hpp"
    #include <GL/glut.h>

class AGraphical: public IGraphical {
    public:
    AGraphical()
        : _eventBinding{ nullptr} {};
    ~AGraphical() {};

    // IGraphical
    virtual void loadResource() {};
    virtual void resetResource() {};

    //IWindow
    virtual void openWindow() final;
    virtual void closeWindow() final;
    virtual void initWindow(std::string, std::pair<size_t, size_t>) final;
    virtual bool windowIsOpen() final;
    virtual void clear() final;
    virtual void display() final;

    //IEvent
    virtual void loadEventBindings(EventHandler &) final {};

    // IEntity
    virtual void create() final {};

    virtual void setSize() final {};

    virtual void setPosition() final {};

    virtual void destroy() final {};

    virtual void displayEntity() final {};

    private:
        void callEvent(const IEvent::EventType);

        EventHandler *_eventBinding;
        std::unordered_map<int, bool> keyState;
};
