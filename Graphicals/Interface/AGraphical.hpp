/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphical
*/

#pragma once
#include "../../Core/include/various.hpp"
#include "../../Interface/Graphical/IGraphicals.hpp"

template <typename GraphicalInfo>
class AGraphical: public IGraphical {
protected:
    EventHandler _eventBinding;
    GraphicalInfo graphicalInfo;

    void callEvent(const IEvent::EventType eventType) {
        if (_eventBinding.count(eventType) <= 0)
            throw std::runtime_error("--! [GAME Logic] no event binded");
        _eventBinding[eventType]();
    }

public:
    AGraphical() {};
    ~AGraphical() {};

    // IGraphical
    virtual void loadResource() {};
    virtual void resetResource() {};

    //IWindow
    virtual void openWindow() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void closeWindow() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void initWindow(std::string, std::pair<size_t, size_t>) override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual bool windowIsOpen() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void clear() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void display() override {
        throw std::runtime_error("graphical method not implemented");
    };

    //IEvent
    virtual void loadEventBindings(EventHandler &eventBinding) override {
        _eventBinding.insert(eventBinding.begin(), eventBinding.end());
    };

    // IEntity
    virtual void create() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void setSize() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void setPosition() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void destroy() override {
        throw std::runtime_error("graphical method not implemented");
    };

    virtual void displayEntity() override {
        throw std::runtime_error("graphical method not implemented");
    };
};