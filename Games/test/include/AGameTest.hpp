/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameTest : public AGame<GameEngine>
{
    private:
    public:
        AGameTest() = default;
        ~AGameTest() = default;

        IEvent::EventHandler &getEventBinding() final;
        void processGameTick(IClock &clock) final;
        std::vector<IEntity> getEntity() final;
};
