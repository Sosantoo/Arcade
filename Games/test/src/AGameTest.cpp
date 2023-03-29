/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** AGameTest
*/

#include "AGameTest.hpp"

IEvent::EventHandler &AGameTest::getEventBinding()
{
    return gameEngine.getEventBindings();
};

void AGameTest::processGameTick(IClock &clock)
{
    gameEngine.processGameTick(clock);
};

std::vector<IEntity> AGameTest::getEntity()
{
    return {};
};
