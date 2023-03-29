/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AGameSnake
*/

#include "AGameSnake.hpp"

IEvent::EventHandler &AGameSnake::getEventBinding() {
    return gameEngine.getEventBindings();
};

void AGameSnake::processGameTick(IClock &clock) {
    gameEngine.processGameTick(clock);
};

std::vector<IEntity> AGameSnake::getEntity() {
    return {};
};
