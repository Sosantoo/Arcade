/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGraphical
*/

#pragma once
#include "../../Core/include/various.hpp"
#include "../../Interface/Graphical/IGraphicals.hpp"

class AClock : public IClock
{
    private:
        time_t time;

    public:
        AClock() = default;
        ~AClock() = default;
        void startClock() override{};

        time_t getTimeElapsed() override { return time; };

        void resetClock() override{};

        void initClock() override{};

        IClock &getClock() override { return *this; };
};

template <typename GraphicalInfo> class AGraphical : public IGraphical
{
    protected:
        EventHandler _eventBinding;
        GraphicalInfo graphicalInfo;
        AClock _clock;

        void callEvent(const IEvent::EventType eventType)
        {
            if (_eventBinding.count(eventType) <= 0)
                throw std::runtime_error("--! [GAME Logic] no event binded");
            _eventBinding[eventType]();
        }

    public:
        AGraphical() = default;
        ~AGraphical() = default;

        // IGraphical
        void loadResource() override
        {
            throw std::runtime_error("graphical method not implemented loadResource");
        };

        void destroyRessource() override
        {
            throw std::runtime_error("graphical method not implemented destroyRessource");
        };

        void displayEntity(std::vector<IEntity>) override
        {
            throw std::runtime_error("graphical method not implemented displayEntity");
        };

        // IWindow
        void initWindow(std::string, std::pair<size_t, size_t>) override
        {
            throw std::runtime_error("graphical method not implemented initWindow");
        };

        void closeWindow() override
        {
            throw std::runtime_error("graphical method not implemented closeWindow");
        };

        bool windowIsOpen() override
        {
            throw std::runtime_error("graphical method not implemented windowIsOpen");
        };

        void clear() override
        {
            throw std::runtime_error("graphical method not implemented clear");
        };

        void display() override
        {
            throw std::runtime_error("graphical method not implemented display");
        };

        // IEvent
        void loadEventBindings(EventHandler &eventBinding) override
        {
            _eventBinding.insert(eventBinding.begin(), eventBinding.end());
        };

        void eventPollEvent() override
        {
            throw std::runtime_error("graphical method not implemented EventPollEvent");
        };

        // IClock
        void startClock() override { _clock.startClock(); };

        time_t getTimeElapsed() override { return _clock.getTimeElapsed(); };

        void resetClock() override { _clock.resetClock(); };

        void initClock() override { _clock.initClock(); };

        IClock &getClock() override { return _clock.getClock(); };
};