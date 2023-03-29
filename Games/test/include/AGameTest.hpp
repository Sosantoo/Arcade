/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#pragma once
#include "../../Interface/AGame.hpp"

class AGameTest : public AGame
{
    private:
        void upKeyPress();
        void downKeyPress();
        void leftKeyPress();
        void rightKeyPress();
        IEvent::EventHandler gameEvent;

    public:
        AGameTest() = default;
        ~AGameTest() = default;

<<<<<<< HEAD
        IEvent::EventHandler &getEventBinding() final;
        void processGameTick(IClock &clock) final;
        std::vector<IEntity> getEntity() final;
=======
    virtual IWindow::EventHandler &getEventBinding() final;

    virtual void processGameTick(IClock &clock) final;

    virtual std::vector<IEntity> getEntity() final;
>>>>>>> origin/refacto/GraphicalInterface
};
