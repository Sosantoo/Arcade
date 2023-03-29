/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Snake
*/

#pragma once
#include "../../Interface/AGame.hpp"
#include "GameEngine.hpp"

class AGameSnake : public AGame<GameEngine>
{
    private:
    public:
        AGameSnake() = default;
        AGameSnake(IGraphical &, IEvent::EventHandler &){};
        ~AGameSnake() = default;
        IEvent::EventHandler &getEventBinding() final;
        void processGameTick(IClock &clock) final;
        std::vector<IEntity> getEntity() final;
};