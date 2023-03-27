/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphical
*/

#pragma once
#include "../../Core/include/various.hpp"
#include "../../Interface/Graphical/IGraphicals.hpp"

class AClock: public IClock {
private:
        time_t time;

public:
    AClock() {};
    ~AClock() {};

    virtual void startClock() {};

    virtual time_t getTimeElapsed() { return time; };

    virtual void resetClock() {};

    virtual void initClock() {};

    virtual IClock &getClock() { return *this; };
};

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
    virtual void loadResource() override {
        throw std::runtime_error("graphical method not implemented loadResource");
    };

    virtual void destroyRessource() override {
        throw std::runtime_error("graphical method not implemented destroyRessource");
    };

    virtual void displayEntity(std::vector<IEntity>) override {
        throw std::runtime_error("graphical method not implemented displayEntity");
    };

    //IWindow
    virtual void initWindow(std::string, std::pair<size_t, size_t>) override {
        throw std::runtime_error("graphical method not implemented initWindow");
    };

    virtual void closeWindow() override {
        throw std::runtime_error("graphical method not implemented closeWindow");
    };

    virtual bool windowIsOpen() override {
        throw std::runtime_error("graphical method not implemented windowIsOpen");
    };

    virtual void clear() override {
        throw std::runtime_error("graphical method not implemented clear");
    };

    virtual void display() override {
        throw std::runtime_error("graphical method not implemented display");
    };

    //IEvent
    virtual void loadEventBindings(EventHandler &eventBinding) override {
        _eventBinding.insert(eventBinding.begin(), eventBinding.end());
    };

    virtual void eventPollEvent() override {
        throw std::runtime_error("graphical method not implemented EventPollEvent");
    };

    // IClock
    virtual void startClock()override {
        throw std::runtime_error("graphical method not implemented startClock");
    };

    virtual time_t getTimeElapsed()override {
        throw std::runtime_error("graphical method not implemented getTimeElapsed");
        return 0.0;
    };

    virtual void resetClock()override {
        throw std::runtime_error("graphical method not implemented resetClock");
    };

    virtual void initClock()override {
        throw std::runtime_error("graphical method not implemented initClock");
    };

    virtual IClock &getClock()override {
        throw std::runtime_error("graphical method not implemented getClock");
    };
};